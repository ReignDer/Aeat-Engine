#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Aeat {
	class AEAT_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnDikit() {}
		virtual void OnTanggalin() {}
		virtual void OnHimaton() {}
		virtual void OnImGuiRender() {}
		virtual void OnPangyayari(Event& event) {} 

		inline const std::string& KuninName() const { return m_DebugPangalan; }


	protected:
		std::string m_DebugPangalan;
	};
}

