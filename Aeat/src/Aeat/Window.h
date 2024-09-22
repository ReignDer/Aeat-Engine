#pragma once

#include "aepch.h"

#include "Core.h"
#include "Events/Event.h"

namespace Aeat {
	struct WindowProps {
		std::string Pamagat;
		unsigned int Laki;
		unsigned int Haba;

		WindowProps(const std::string& pamagat = "Aeat Engine",
			unsigned int laki = 1280,
			unsigned int haba = 720) :
			Pamagat(pamagat), Laki(laki), Haba(haba) {}
	};

	//Interface representing a desktop system based window
	class AEAT_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window(){}

		virtual void OnHimaton() = 0;

		virtual unsigned int KuninWidth() const = 0;
		virtual unsigned int KuninHeight() const = 0;

		//Window Attributes
		virtual void ItakdaEventCallback(const EventCallbackFn& tawaginMuli) = 0;
		virtual void ItakdaVsync(bool pinagana);
		virtual bool VsyncBa() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}