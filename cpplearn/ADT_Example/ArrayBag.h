/* Header file for an array-based implementation of the ADT bag 
 * @file ArrayBag.h */
#include <vector>
template<class ItemType>
class ArrayBag {
private:
	static const int DEFAULT_CAPACITY = 8;
	ItemType items[DEFAULT_CAPACITY];
	int itemCount;
	int maxItem;
	int getIndexOf(const ItemType& target) const;
	void swap(const int i, const int j);
public:
	ArrayBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
	std::vector<ItemType> toVector() const;
};// end of ArrayBag

