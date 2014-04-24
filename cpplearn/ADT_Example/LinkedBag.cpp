/* implement of LinkedBag class 
 * @file LinkedBag.cpp
 * just for practice, not test*/ 
#include "LinkedBag.h"

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {

}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &aBag) {
	itemCount = aBag.itemCount;
	Node<ItemType> *origChainPtr = aBag->headPtr;

	if (origChainPtr == nullptr) {
		headPtr = nullptr;
	} else {
		// copy the first one
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// copy the rest 
		Node<ItemType> *newChainPtr = headPtr;
		while(newChainPtr != nullptr) {
			// next item from origin
			origChainPtr = origChainPtr->getNext();
			// create a new node corresponding to the origin
			Node<ItemType> *newNodePtr = new Node<ItemType>();
			newNodePtr->setItem(origChainPtr->getItem());

			// link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			newChainPtr = newChainPtr->getNext();
		}
	} // end of if
} // end of LinkedBag

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &newEntry) {
	// add to the beginning of chain
	Node<ItemType> *newNodePtr = new Node<ItemType>();
	newNodePtr->setItem(newEntry);
	newNodePtr->setNext(headPtr);
	headPtr = newNodePtr; // new node is the first node now
	itemCount += 1;

	return true;
}

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const {
	vector<ItemType> bagContent;
	Node<ItemType> *curptr = headPtr;
	int counter = 0;

	while(curptr != nullptr && counter < itemCount) {
		bagContent.push_back(curptr->getItem());
		curptr = curptr->getNext();
		counter += 1;
	}
	return bagContent;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
	return itemCount == 0;
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
	retur itemCount;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
	Node<ItemType> *curptr = headPtr;
	int frequency = 0;
	int counter = 0;

	while (curptr != nullptr && counter < itemCount) {
		if (curptr->getItem() == anEntry) {
			frequency += 1;
		}
		counter += 1;
		curptr = curptr->getNext();
	}
	return frequency;
}

// return either a pointer ot the node containing a given entry
// or the null pinter if the entry is ot in the bag
template<class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &target) const {
	bool found = false;
	Node<ItemType> *curptr = headPtr;

	while (!found && curptr != nullptr) {
		if (curptr->getItem() == target) {
			found = true;
		} else {
			curptr = curptr->getNext();
		}
	}

	return curptr;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &anEntry) const {
	return (getFrequencyOf(anEntry) != nullptr);
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry) {
	Node<ItemType> *entryNodePtr = getPointerTo(anEntry);
	bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

	if (canRemoveItem) {
		// replace the entry with the first one
		entryNodePtr->setItem(headPtr->getItem());
		// delete the first one in the chain
		Node<ItemType> *nodeToDeletePtr = headPtr; // we need to tracd the memory, which need to delete
		headPtr = headPtr->getNext();
		// delete 
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount -= 1;
	} // end of if
	return canRemoveItem;
} // end of remove

template<class ItemType>
void LinkedBag<ItemType>::clear() {
	Node<ItemType> *nodeToDeletePtr = headPtr;

	while (headPtr != nullptr) {
		headPtr = headPtr->getNext();
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = headPtr;
	}
	itemCount = 0;
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
	clear();
} // end of destructor

