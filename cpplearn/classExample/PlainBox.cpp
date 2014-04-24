/* @file PlainBox.cpp */
#include "PlainBox.h"
template<class ItemType>
PlainBox<ItemType>::PlainBox() {
// do nothing
}

template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem) {
	item = theItem;
}

template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem) {
	item = theItem;
}

template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const {
	return item;
}
