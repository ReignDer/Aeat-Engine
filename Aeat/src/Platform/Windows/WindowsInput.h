#pragma once

#include "../../Aeat/Application.h"
#include "../../vendor/GLFW_new/include/GLFW/glfw3.h"
#include "../../Aeat/Input.h"

namespace Aeat {
	class WindowsInput : public Input
	{
	protected:
		virtual bool NagawaPindotKey(int keyKodigo) override;
		virtual bool NagawaPindotMousePindutan(int pindutan) override;
		virtual std::pair<float, float> NagawaKuninMousePosition() override;
		virtual float NagawaKuninMouseX() override;
		virtual float NagawaKuninMouseY() override;
	};
}

