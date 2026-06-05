#include "Geode/cocos/actions/CCAction.h"
#include "Geode/cocos/actions/CCActionInstant.h"
#include "Geode/cocos/actions/CCActionInterval.h"
#include "Geode/cocos/cocoa/CCObject.h"
#include "Geode/cocos/robtop/keyboard_dispatcher/CCKeyboardDispatcher.h"
#include "Geode/ui/Notification.hpp"
#include <Geode/Geode.hpp>
#include <Geode/binding/PauseLayer.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include <Geode/binding/PlayLayer.hpp>
#include <chrono>

using namespace geode::prelude;

#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

class $modify(MyPlayLayer, PlayLayer) {
    void pauseGame(bool unfocused) {
        bool shift = CCKeyboardDispatcher::get()->getShiftKeyPressed();
        if(shift) {
            PlayLayer::onQuit();
        }
        else PlayLayer::pauseGame(unfocused);
    }
};

class $modify(MyPauseLayer, PauseLayer){
    void tryQuit(CCObject* sender) {
       bool shift = CCKeyboardDispatcher::get()->getShiftKeyPressed();
       if(shift) {
            PauseLayer::tryQuit(sender);
       }
       else PauseLayer::onResume(nullptr);
    }

};