#include "ppButton.h"

namespace pp {
namespace ui {

struct ppButton::Private {

};

ppButton::ppButton(QWidget * parent) noexcept 
:super(parent){

}

ppButton::ppButton(QString label, QWidget * parent) noexcept 
:ppButton(parent){

}

ppButton::~ppButton() noexcept {
}

}
}