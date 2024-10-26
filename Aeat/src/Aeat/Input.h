#pragma once

#include "Core.h"

namespace Aeat {
	class AEAT_API Input
	{
	public:
		inline static bool NapindotKey(int key) { return s_Instance->NagawaPindotKey(key); }
		inline static bool NapindotMousePindutan(int pindutan) { return s_Instance->NagawaPindotMousePindutan(pindutan); }
		inline static std::pair<float,float> KuninMousePosition() { return s_Instance->NagawaKuninMousePosition(); }
		inline static float KuninMouseX() { return s_Instance->NagawaKuninMouseX(); }
		inline static float KuninMouseY() { return s_Instance->NagawaKuninMouseY(); }
	protected:
		virtual bool NagawaPindotKey(int key) = 0;
		virtual bool NagawaPindotMousePindutan(int pindutan) = 0;

		virtual std::pair<float,float> NagawaKuninMousePosition() = 0;
		virtual float NagawaKuninMouseX() = 0;
		virtual float NagawaKuninMouseY() = 0;
	private: 
		static Input* s_Instance;

	};
}
