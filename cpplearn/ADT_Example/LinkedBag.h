/* ADT bag: Link-based implementation 
 * @file LinkedBag
 * just for practice, not test */

#include "Node.h"
#include <vector>
using namespace std;

template<class ItemType>
class LinkedBag {
private:
	Node<ItemType> *headPtr; // pointer to the first node
	int itemCount; // current count of bog items
	// return a pointer  to the node containing a given entry
	// or nullptr if the entry is not in the bag
	Node<ItemType> *getPointerTo(const ItemType& target) const;

public:
	LinkedBag();
	LinkedBag(const LinkedBag<ItemType> &aBag); // copy constructor
	virtual ~LinkedBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType &newEntry);
	bool remove(const ItemType &anEntry);
	void clear();
	bool contains(const ItemType &anEntry) const;
	int getFrequencyOf(const ItemType &anEntry) const;
	vector<ItemType> toVector() const;
}; // end of LinkedBag