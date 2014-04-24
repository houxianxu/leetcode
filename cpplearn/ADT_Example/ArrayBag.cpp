/* Implementation file for the class ArrayBag
 * @fiel ArrayBag.cpp */
#include "ArrayBag.h"
#include <vector>

template<class ItemType>
ArrayBag<ItemType>::ArrayBag() {
	itemCount = 0;
	maxItem = DEFAULT_CAPACITY;
} // end of default structor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {
	return itemCount;
} // end of getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry) {
	if (itemCount < maxItem) {
		items[itemCount] = newEntry;
		itemCount++;
		return true;
	} else {
		return false;
	}// end of if
} // end of add

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const {
	std::vector<ItemType> bagContents;
	for (int i = 0; i< maxItem; i++) {
		bagContents.push_back(items[i]);
	}
	return bagContents;
}

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
	int frequency = 0;
	for (int i = 0; i < maxItem; i++) {
		if (items[i] == anEntry) {
			frequency += 1;
		} // end of if
	} // end of for
	return frequency;
}

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {
	return (getFrequencyOf(anEntry) > 0);
}

template<class ItemType>
void ArrayBag<ItemType>::clear() {
	itemCount = 0;
}

template<class ItemType>
void ArrayBag<ItemType>::swap(const int i, const int j) {
	ItemType tmp;
	tmp = items[i];
	items[i] = items[j];
	items[j] = tmp;
}
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry) {
	// scan from right to left, when find the anEntry, then swap with the last one
	// if the last one is == anEntry, then itemCount--
	bool canRemove = false;
	if (!isEmpty()) {
		int i = itemCount;
		for (; i >= 0; i--) {
			if (items[i] == anEntry) {
				swap(i, itemCount);
				itemCount -= 1;
				canRemove = true;	
			}
		}
	}
	return canRemove;
}

