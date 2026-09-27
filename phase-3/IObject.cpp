#include "IObject.h"

int IObject::contorGlobal = 0;

IObject::IObject():id(++contorGlobal) {}
IObject::~IObject() noexcept {}
int IObject::getId() const noexcept { return id; }
bool IObject::operator==(const IObject& alt) const noexcept { return id==alt.id; }
ostream& operator<<(ostream& os, const IObject& obj) { return os<<obj.toString(); }