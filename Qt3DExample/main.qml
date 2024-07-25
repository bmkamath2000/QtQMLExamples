import QtQuick 2.12
import QtQuick.Controls 2.12
import Qt3D.Core 2.12
import Qt3D.Render 2.12
import Qt3D.Input 2.12
import Qt3D.Extras 2.12
import test 1.0
Entity {
    id: sceneRoot
    property QtObject modelData: null
    property QtObject modelGeometry
    OMR{
        id:omr

        Component.onCompleted:
        {
            loadModelData()
        }
    }
    Camera {
        id: camera
        projectionType: CameraLens.PerspectiveProjection
        fieldOfView: 45
        aspectRatio: 16/9
        nearPlane : 0.1
        farPlane : 1000.0
        position: Qt.vector3d( 0.0, 0.0, -40.0 )
        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
    }

    OrbitCameraController {
        camera: camera
    }

    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                clearColor: Qt.rgba(0, 0.5, 1, 1)
                camera: camera
                //showDebugOverlay: true
            }
        },
        // Event Source will be set by the Qt3DQuickWindow
        InputSettings { }
    ]

    PhongMaterial {
        id: material
    }

    Entity{
        GeometryRenderer {
            id: geometry
            primitiveType: GeometryRenderer.TriangleStrip
            geometry: sceneRoot.modelGeometry
        }
        Transform {
            id: sphereTransform123
            property real userAngle: 0.5
            //matrix: Qt.matrix4x4(1.0)
            scale3D: Qt.vector3d(4.0,4.0,4.0)
        }
        components: [geometry, material, sphereTransform123 ]
    }
    ModelData{
        id:md
    }


    function loadModelData()
    {
        md.createModel(omr)
        sceneRoot.modelGeometry=_controller.createGeometry(md)
    }
}
