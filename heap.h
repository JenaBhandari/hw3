#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  
  std::vector<T> getVector();


private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> theHeap;
	PComparator c_;
  int num;

	int parent(int i);
	int childk(int i, int k);
	void heapify(int i);

};



//-----------------------------------------------------------------------
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): num(m), c_(c)
{

}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}
//-----------------------------------------------------------------------
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
	return theHeap.size();
}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
int Heap<T, PComparator>::parent(int i)
{
	return (i-1)/num;
}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
int Heap<T, PComparator>::childk(int i, int k)
{
	return ( (num * i) + k);
}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int i) {

	int curMaxIndex = i;
	int size = theHeap.size();



	//iterate through each child
	for (int j = 1; j <= num; j++)
	{
		int childIndex = childk(i, j);
		//if curMax has the jth child
		if (size > childIndex)
		{
			//functor comparison here
			if (c_(theHeap[childIndex], theHeap[curMaxIndex]))
			{
				curMaxIndex = childIndex;
			}
		}
	}

	if (curMaxIndex != i)
	{
		std::swap(theHeap[i], theHeap[curMaxIndex]);
		heapify(curMaxIndex);
	}

}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
	if (theHeap.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//-----------------------------------------------------------------------
// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T, PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack Underflow");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

	return theHeap[0];

}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
	theHeap.push_back(item);

  std::size_t index = theHeap.size() - 1;

    while (index != 0) 
		{
        std::size_t parent_index = parent(index);

        T& current = theHeap[index];
        T& parent = theHeap[parent_index];

        if ( c_(parent, current) ) 
				{
            break;
        }

        std::swap(current, parent);

        index = parent_index;
				
    }

}

//-----------------------------------------------------------------------
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Stack Underflow");
  }

	//swap best item with last item
	std::swap(theHeap[0], theHeap[theHeap.size() - 1]);

	//delete last item
	theHeap.pop_back();

	if (theHeap.size() > 1)
	{
		heapify(0);
	}

}

//-----------------------------------------------------------------------


#endif

