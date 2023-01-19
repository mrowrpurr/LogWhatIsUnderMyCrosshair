#include <SkyrimScripting/Plugin.h>

class ModEventEventSink : public RE::BSTEventSink<SKSE::CrosshairRefEvent> {
public:
    RE::BSEventNotifyControl ProcessEvent(const SKSE::CrosshairRefEvent* event,
                                          RE::BSTEventSource<SKSE::CrosshairRefEvent>*) override {
        auto* ref = event->crosshairRef.get();
        if (ref) {
            auto* base = ref->GetBaseObject();
            logger::info("REF:{:x} [{}] '{}' | BASE:{:x} [{}] '{}'", ref->GetFormID(), ref->GetFormEditorID(),
                         ref->GetDisplayFullName(), base->GetFormID(), base->GetFormEditorID(), base->GetName());
        }
        return RE::BSEventNotifyControl::kContinue;
    }
};

OnInit { SKSE::GetCrosshairRefEventSource()->AddEventSink(new ModEventEventSink()); }
