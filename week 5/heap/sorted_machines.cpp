#include <stdio.h>
struct ListNode
{
	int data;
	struct ListNode* next;
};

struct MinHeapNode
{
	ListNode* head;
};
struct MinHeap
{
	int count;
	int capacity;
	MinHeapNode* array;
};
MinHeap* createMinHeap( int capacity )
{
	MinHeap* minHeap = new MinHeap;
	minHeap->capacity = capacity;
	minHeap->count = 0;
	minHeap->array = new MinHeapNode [minHeap->capacity];
	return minHeap;
}
void push (ListNode** head_ref, int new_data)
{
	
	ListNode* new_node = new ListNode;

	
	new_node->data = new_data;

	
	new_node->next = (*head_ref);

	
	(*head_ref) = new_node;
}

void swap( MinHeapNode* a, MinHeapNode* b )
{
	MinHeapNode temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify( MinHeap* minHeap, int idx )
{
	int left, right, smallest;
	left = 2 * idx + 1;
	right = 2 * idx + 2;
	smallest = idx;

	if ( left < minHeap->count &&
		minHeap->array[left].head->data <
		minHeap->array[smallest].head->data
	)
		smallest = left;

	if ( right < minHeap->count &&
		minHeap->array[right].head->data <
		minHeap->array[smallest].head->data
	)
		smallest = right;

	if( smallest != idx )
	{
		swap( &minHeap->array[smallest], &minHeap->array[idx] );
		minHeapify( minHeap, smallest );
	}
}


int isEmpty( MinHeap* minHeap )
{
	return (minHeap->count == 0);
}

void buildMinHeap( MinHeap* minHeap )
{
	int i, n;
	n = minHeap->count - 1;
	for( i = (n - 1) / 2; i >= 0; --i )
		minHeapify( minHeap, i );
}


void populateMinHeap( MinHeap* minHeap, ListNode* *array, int n )
{
	for( int i = 0; i < n; ++i )
		minHeap->array[ minHeap->count++ ].head = array[i];

	buildMinHeap( minHeap );
}


ListNode* extractMin( MinHeap* minHeap )
{
	if( isEmpty( minHeap ) )
		return NULL;

	
	MinHeapNode temp = minHeap->array[0];

	
	if( temp.head->next )
		minHeap->array[0].head = temp.head->next;
	else 
	{
		minHeap->array[0] = minHeap->array[ minHeap->count - 1 ];
		--minHeap->count;
	}

	minHeapify( minHeap, 0 );
	return temp.head;
}


void externalSort( ListNode *array[], int N )
{
	
	MinHeap* minHeap = createMinHeap( N );

	
	populateMinHeap( minHeap, array, N );

	while ( !isEmpty( minHeap ) )
	{
		ListNode* temp = extractMin( minHeap );
		printf( "%d ",temp->data );
	}
}


int main()
{
	int N = 3; 

	
	ListNode *array[N];

	
	array[0] = NULL;
	push (&array[0], 50);
	push (&array[0], 40);
	push (&array[0], 30);

	
	array[1] = NULL;
	push (&array[1], 45);
	push (&array[1], 35);

	
	array[2] = NULL;
	push (&array[2], 100);
	push (&array[2], 80);
	push (&array[2], 70);
	push (&array[2], 60);
	push (&array[2], 10);

	
	externalSort( array, N );

	return 0;
}
