
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;



struct edge
{
	int vertex1;
	int vertex2;
	int weight;
};

struct node
{
	int key; //priority of the node. Lower is better
	int rank;
	node * parent;
	node * child;
	node * next; //brother pointer
	int i; // in the heap
};

struct vertice
{

	vertice()
	{
		gone = false;
		best = 0; 
		inHeap = 0; 
		i = 0;
	}

	bool gone;
	edge * best;
	node * inHeap;
	vector <edge*> connexions; 
	int i; 
};


vector <vertice> vertices; 

void mergeTree(node * y, node * z)
{
		y->parent = z;
		y->next = z->child;
		z->child = y;
		z->rank++;
}


node* fusionnerTasBinomiaux(node * heap1, node * heap2)
{
	
	if (heap1 == NULL)
		return heap2;

	if (heap2 == NULL)
		return heap1;

	node * newheap;
	node * newheap_head;

	
	if (heap1->rank < heap2->rank)
	{
		newheap = heap1;
		heap1 = heap1->next;
	}
	else 
	{
		newheap = heap2;
		heap2 = heap2->next;
	}

	newheap_head = newheap;

	while (heap1 != NULL && heap2 != NULL)
	{
		
		if (heap1->rank < heap2->rank)
		{
			newheap->next = heap1;
			heap1 = heap1->next;
			newheap = newheap->next;
		}
		
		else
		{
			newheap->next = heap2;
			heap2 = heap2->next;
			newheap = newheap->next;
		}
	}

	while (heap1 != NULL)
	{
		newheap->next = heap1;
		heap1 = heap1->next;
		newheap = newheap->next;
	}

	while (heap2 != NULL)
	{
		newheap->next = heap2;
		heap2 = heap2->next;
		newheap = newheap->next;
	}

	return newheap_head;

}

node* mergeHeap(node * heap1, node * heap2)
{

	node * newheap = fusionnerTasBinomiaux(heap1, heap2);
	if (newheap == NULL)
		return newheap;

	node * x = NULL; 
	node * apres_x = NULL;
	node * avant_x = NULL;


	x = newheap;
	apres_x = newheap->next;



	while (apres_x != NULL)
	{

		
		if (x->rank != apres_x->rank || apres_x->next != NULL && apres_x->next->rank == x->rank )
		{
			avant_x = x;
			x = apres_x;
		}

		else
		{
		
			if (x->key <= apres_x->key )
			{
				x->next = apres_x->next;
				mergeTree(apres_x, x);
			}
			else 
			{
				if (avant_x == NULL)
					newheap = apres_x;
				else 
					avant_x->next = apres_x;

				mergeTree(x, apres_x);
				x = apres_x;
			}
		}

		apres_x = x->next;
	}
	return newheap;
}

void initNode(node * a)
{
	memset(a, 0, sizeof(node));
}

node * insert(node * destination, node * source)
{
	node * heapAfterInsert = mergeHeap(destination, source);
	return heapAfterInsert;
}

node * findMinimum(node * heap)
{

	node * current;
	node * next;
	node * min;

	current = heap;
	next = heap->next;
	min = current;

	if (next == NULL)
		return current;

	while (next != NULL)
	{
		if (current->key < min->key)
			min = current;

		current = next;
		next = current->next;
	}

	if (current->key < min->key)
		min = current;

	return min;
}


node * extractMin(node * heap)
{
	
	node * x = findMinimum(heap);
	node * before = NULL;
	node * iterator = heap;

	while (iterator != x)
	{
		before = iterator;
		iterator = iterator->next;
	}

	if (before == NULL) {
		heap = x->next;

	}
	else {
		before->next = x->next;
	}

	node * fils = x->child;

	if (fils == NULL) 
	{
		return heap;
	}

	node * courant;
	node * precedent = 0;
	node * frere;
	int i = 0;
	courant = fils;

	
	while ( courant != NULL)
	{
		if (precedent > 0)
		{
			courant->parent = NULL; 
			frere = courant->next; 
			courant->next = precedent;
			precedent = courant;
			courant = frere;
		}
		//1ere itération
		else
		{
		precedent = courant;
		courant = courant->next;
		precedent->next = NULL; 
		precedent->parent = NULL;
		}
	}
	
	node * teteListeEnfants = precedent;

	node * resultat =  mergeHeap( heap, teteListeEnfants);
	return resultat;
}

void swap_parent_child(node * child, node * parent)
{
	int tmp = child->key;
	child->key = parent->key;
	parent->key = tmp;
	int indexParent = parent->i;
	int indexChild = child->i;

	vertices[indexParent].inHeap = child;
	vertices[indexChild].inHeap = parent;

	child->i = indexParent;
	parent->i = indexChild;

}


void decreaseKey(node * element, int newValue)
{
	
	element->key = newValue;
	node * i = element;

	if (i->parent == NULL)
		return ;

	while (i->parent != NULL)
	{
		int clParent = i->parent->key;
		if (clParent > i->key )
		{
			swap_parent_child(i, i->parent);
		}
		else break;
		i = i->parent;
	}
}


void printSmall(node * heap)
{
	printf("\n");
	node * racine = heap;
	printf("%d ",racine->key);
	racine = heap->next;

	while (racine != NULL)
	{
		printf("%d ",racine->key);
		racine = racine->next;
	}

}


void printTas(node * start)
{
	printSmall(start);

	node * enfantCourant = start->child;
	if (enfantCourant != NULL)
	{
		do
		{
			printTas(enfantCourant);
			enfantCourant = enfantCourant->next;

		} while (enfantCourant != NULL);

	}

	return ;

}

void printAllHeap(node * heap)
{

	node dummy;
	initNode(&dummy);
	dummy.child = heap;
	printTas(&dummy);
}

int main(int argc, char * argv[])
{

	printf("\nThe MST of the given graph is:\n");
	FILE* fichier;

	if (argc == 2) {
		fichier = fopen(argv[1], "r");
	}
	else 
		fichier = fopen("graph_poids.txt", "r");

    static char ligne[50]; 
	bool premiereLignefaite = false; //on traite la premiere ligne du fichier differemment
	int nb_sommets;
	int nb_aretes;

	node * heap = NULL;

    while (fgets(ligne, 50, fichier) != NULL) //retourne 0 quand on a end-of-file
    {
        //La premiere ligne est différente
        if (premiereLignefaite == false) {

            //On va besoin d'avoir une matrice de N tas
            sscanf(ligne, "%d %d", &nb_sommets, &nb_aretes );

			vertices.resize(nb_sommets); //resize ou reserve?

			for (int i = 0; i < nb_sommets; i++) {
				node *tmp = new node;
				initNode(tmp);
				tmp->key = INT_MAX;
				tmp->i = i;

				//Mettre le pointeur dans le tableau qui sauvegarde les pointeurs de sommets
				vertices[i].inHeap = tmp;
				vertices[i].i = i;

				heap = mergeHeap(	heap, tmp);
			
			}

			//printAllHeap(heap);

            premiereLignefaite = true;
            continue;
        }
        //On construit notre liste d'arêtes
		int sommet1, sommet2, poids;
		sscanf(ligne, "%d %d %d", &sommet1, &sommet2, &poids);

		edge * areteLue = new edge;

		areteLue->vertex1 = sommet1;
		areteLue->vertex2 = sommet2;
		areteLue->weight = poids;

		vertices[sommet1].connexions.push_back(areteLue);
		vertices[sommet2].connexions.push_back(areteLue);

    }
	//Boucle principale de l'algorithme de Prim
	vertice * min;
	node * heap_min;
	decreaseKey(vertices[0].inHeap, 0);
	//printAllHeap(heap);
	min = &vertices[0];

	min->gone = true;

	// min->primsparent=NULL;

    map<int,int> pmap;
    pmap[0]=777777777;

	while (1)
	{

		
		heap = extractMin(heap);
		if (heap == NULL)
			break;
		for (int i = 0; i < min->connexions.size() ; i++)
		{
			edge * tmp = min->connexions[i];

			//printf("Decrease key : %d %d %d\n", tmp->vertex1, tmp->vertex2, tmp->weight);

			
			int destination;
			if ( min->i == tmp->vertex1)
				destination = tmp->vertex2;
			else destination = tmp->vertex1;

			vertice * vertice_destination = &vertices[destination];

			if (!vertice_destination->gone)
			{
				
				if (vertice_destination->best == NULL) {
					pmap[destination]=tmp->vertex1;
					vertice_destination->best = tmp;
					decreaseKey(  vertice_destination->inHeap, tmp->weight);
				}

				
				else if (vertice_destination->best->weight > tmp->weight )
				{
					vertice_destination->best = tmp;
					pmap[destination]=tmp->vertex1;
					decreaseKey(  vertice_destination->inHeap, tmp->weight);
				}

			}

		}

		

		//printf("\n\nLE HEAP APRES LES DECREASEKEY + son extraction sommet %d key %d\n", min->i, min->inHeap->key);
		//printAllHeap(heap);

		heap_min = findMinimum(heap);
		min = &vertices[heap_min->i];
		min->gone = true;


	}


	int poidsTotal = 0;
	for (int i = 1; i < nb_sommets; i++)
	{
		poidsTotal += vertices[i].best->weight;
	}
	for(auto it:pmap)
	{
		if(it.first!=0)
		cout<<it.first<<" "<<it.second<<endl;
	}

	printf("total weight in MST : %d\n", poidsTotal);

	return 0;
}