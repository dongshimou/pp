#include "talk.h"

namespace pp {

struct talk::Private {
    userID uid;
};

void talk::init() {
}

talk::talk(userID uid, QWidget * parent) noexcept
:super(TALK_WINDOW,parent){

}

talk::~talk() {
}



}
