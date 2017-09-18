#include "talk.h"

namespace pp {

struct talk::Private {
    userID uid;
};

void talk::init() {
}

talk::talk(userID uid) noexcept
:super(TALK_WINDOW){

}

talk::~talk() {
}



}
