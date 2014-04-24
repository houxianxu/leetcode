/* @file PainBox.h */
template<class ItemType> // indecates this is a template definition

// Delaration for the class PlainBox
class PlainBox {
private:
	ItemType item;
public:
	// Default constructor
	PlainBox();

	// Constructor
	PlainBox(const ItemType& theItem);

	void setItem(const ItemType& theItem);

	ItemType getItem() const;
}; // end of class


