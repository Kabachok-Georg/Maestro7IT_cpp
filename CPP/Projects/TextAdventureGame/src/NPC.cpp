#include "NPC.h"

NPC::NPC(const std::string& name, const std::string& dialog)
    : name(name), dialog(dialog) {}

std::string NPC::getName() const {
    return name;
}

std::string NPC::getDialog() const {
    return dialog;
}

void NPC::setQuest(const std::string& quest) {
    this->quest = quest;
}

std::string NPC::getQuest() const {
    return quest;
}