#ifndef VMV_VECMATHVISUALIZER_H
#define VMV_VECMATHVISUALIZER_H

#include "IMatrix.h"

#include "Core/VMVCamera.h"
#include "Core/VMVDevice.h"
#include "Core/VMVGameObject.h"
#include "Core/VMVModel.h"
#include "Core/VMVRenderer.h"
#include "Core/VMVWindow.h"
#include <map>
#include <memory>
#include <queue>
#include <vector>

namespace vmv
{
    struct GameObjectAddRequest
    {
        std::string modelPath;
        glm::vec4 color;
        VMVGameObject gameObject;
    };

    class VecmathVisualizer
    {
      public:
        VecmathVisualizer();
        ~VecmathVisualizer();

        VecmathVisualizer(const VecmathVisualizer&) = delete;
        VecmathVisualizer(VecmathVisualizer&&) noexcept = delete;
        VecmathVisualizer& operator=(const VecmathVisualizer&) = delete;
        VecmathVisualizer& operator=(VecmathVisualizer&&) noexcept = delete;

        static constexpr uint32_t WIDTH{800};
        static constexpr uint32_t HEIGHT{600};

        void Run();

        void AddVariableDisplay(const std::string& id, IMatrix* pMatrix, float r, float g, float b);
        void ClearVariableDisplays();

      private:
        VMVWindow m_VMVWindow{WIDTH, HEIGHT, "VecMath Visualizer"};
        VMVDevice m_VMVDevice{m_VMVWindow};
        VMVRenderer m_VMVRenderer{m_VMVWindow, m_VMVDevice};

        std::queue<GameObjectAddRequest> m_ToAddNextFrame{};

        std::vector<VMVGameObject> m_GameObjects;
        std::vector<VMVGameObject> m_GameObjects2D;

        void Load();
    };
} // namespace vmv

#endif
