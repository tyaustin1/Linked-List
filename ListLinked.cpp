
#include "ListLinked.h"



template <typename DataType>
List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr)
{
	
	this->dataItem = nodeData;
	this->next = nextPtr;
}



template <typename DataType>
List<DataType>::List(int ignored = 0)
{

	this->head = 0;

	this->cursor = 0;

}

template <typename DataType>
List<DataType>::List(const List& other)
{
	ListNode *temp;

	temp = other.head;

	while (other.head != NULL)
	{
		temp->dataItem = other->dataItem;
		temp->next = other->next; 
		temp = temp->next;
		other = other->next;



	}

}

template <typename DataType>
List<DataType>& List<DataType>::operator=(const List& other)
{
	if (this != other)	
	{
		this->clear;

		while (other.head != NULL)
		{
			temp->dataItem = other->dataItem;
			temp->next = other->next;
			temp = temp->next;
			other = other->next;
		}


	}


	

}

template <typename DataType>
List<DataType>::~List()
{
	this->clear(); 

}

template <typename DataType>
void List<DataType>::insert(const DataType& newDataItem) throw (logic_error)
{
	
	if (head == NULL) {
		ListNode *node;
		node = new ListNode(newDataItem, cursor);
		node->dataItem = newDataItem;
		node->next = head;
		head = node;
		cursor = head;
	}


	else {
		
		ListNode* node;
		node = new ListNode(newDataItem, cursor);
		node->dataItem = newDataItem;
		node->next = head;
		head = node;
		cursor = node;
	}
	

}

template <typename DataType>
void List<DataType>::remove() throw (logic_error)
{
	ListNode *temp, *temp2; 
	temp = head;
	if (head == NULL)
		throw("Trying to remove from empty list");
	
	

	while (temp->next != NULL)
	{
		
		if (temp->next == cursor)
		{
			
			temp2 = cursor;
			cursor = cursor->next;
			temp->next = cursor;
			delete temp2;
			break;
		}
		temp = temp->next;
		
	}
	
}

template <typename DataType>
void List<DataType>::replace(const DataType& newDataItem) throw (logic_error)
{


	cursor->dataItem = newDataItem;

	


}

template <typename DataType>
void List<DataType>::clear()
{
	ListNode *temp, *temp2;
	temp = head;
	
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
		delete temp2;

	}
	delete temp;
	head = NULL;
	
	
}

template <typename DataType>
bool List<DataType>::isEmpty() const
{
	
	if (head == NULL)
		return true;
	else
		return false;

	
}

template <typename DataType>
bool List<DataType>::isFull() const
{

	//Link list can never be full
	return false;
}

template <typename DataType>
void List<DataType>::gotoBeginning() throw (logic_error)
{
	if (head != NULL)
	{
		cursor = head;
	}
}

template <typename DataType>
void List<DataType>::gotoEnd() throw (logic_error)
{
	

	ListNode *tmp;
	tmp = head;
	if (tmp != NULL) 
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			cursor = tmp;
		}

}

template <typename DataType>
bool List<DataType>::gotoNext() throw (logic_error)
{
	if (head != NULL) {
		cursor = cursor->next;
		return true;
	}
	else
		cursor = NULL;
	return false;


}

template <typename DataType>
bool List<DataType>::gotoPrior() throw (logic_error)
{

	ListNode* temp;
	temp = head;

	if (head != NULL) 
	{
		while (temp->next != cursor)
		{
			temp = temp->next;
		}
		cursor = temp;
		return true;
	}
	else
	{
		cursor = NULL;
		return false;
	}
}

template <typename DataType>
DataType List<DataType>::getCursor() const throw (logic_error)
{
	DataType t;

	t = cursor->dataItem;

	return t;
}

template <typename DataType>
void List<DataType>::moveToBeginning () throw (logic_error)
{
	
	ListNode *temp = new ListNode(0, cursor);
	temp->dataItem = cursor->dataItem;
	temp->next = head;
	head = temp;
	
	this->remove();

	


}

template <typename DataType>
void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error)
{
	if (head == NULL) 
	{
		ListNode *node;
		node = new ListNode(newDataItem, cursor);
		node->dataItem = newDataItem;
		node->next = head;
		head = node;
		cursor = head;
	}

	else
	{
		ListNode *temp = head;

		while (temp != NULL)
		{
			temp = temp->next;
			
			if (temp->next == cursor)
			{
				
				ListNode *node;
				node = new ListNode(newDataItem, cursor);
				temp->next = node;
				node->next = cursor;
				cursor = cursor->next;
				cursor = node;
				break;
			}
			
		}




	}



}

#include "show5.cpp"

