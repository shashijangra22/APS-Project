
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;



//Edge structure
struct edge
{
	int vertex1;
	int vertex2;
	int weight;
};

//The main data structure of the binomial heap
//A binomial heap is a collection of node objects
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
		// primsparent=NULL;
		i = 0;
	}

	bool gone; //is the node still in the heap?
	edge * best;
	node * inHeap;
	vector <edge*> connexions; //les connexions
	// vertice *primsparent;
	int i; // vertex number, useful to have
};

//This data structure is used for DecreaseKey
vector <vertice> vertices; //when a pointer is set to NULL, it means that the element does not exist anymore!

//Merge 2 arbres binomiaux de même rang (0 à k)
//L'ordre n'est pas important. Le plus grand noeud devient parent dans tous les cas
void mergeTree(node * y, node * z)
{
		y->parent = z;
		y->next = z->child;
		z->child = y;
		z->rank++;
}

//Cette fonction fusionne deux tas binomiaux sans faire de consolidation
//On ne fait que mettre les éléments du tas binomial résultant en ordre croissant de rank
//rank 0 rank 1 rank 2 rank3
//Il faut que les 2 heaps soient en ordre!!
node* fusionnerTasBinomiaux(node * heap1, node * heap2)
{
	//Pour les merge avec les éléments vides
	if (heap1 == NULL)
		return heap2;

	if (heap2 == NULL)
		return heap1;

	node * newheap;
	node * newheap_head;

	//On choisit la tête entre les premiers éléments des deux listes
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
		//Si c'est l'arbre du heap1 le plus petit rank, on l'ajoute au nouveau tas
		if (heap1->rank < heap2->rank)
		{
			newheap->next = heap1;
			heap1 = heap1->next;
			newheap = newheap->next;
		}
		//Si c'est l'arbre du heap2 le plus petit rank, on l'ajoute au nouveau tas
		else
		{
			newheap->next = heap2;
			heap2 = heap2->next;
			newheap = newheap->next;
		}
	}

	//Vide le tas binomial heap1 dans newheap s'il lui reste des éléments
	while (heap1 != NULL)
	{
		newheap->next = heap1;
		heap1 = heap1->next;
		newheap = newheap->next;
	}


	//Sinon, vide le tas binomial heap2 dans newheap s'il lui reste des éléments
	while (heap2 != NULL)
	{
		newheap->next = heap2;
		heap2 = heap2->next;
		newheap = newheap->next;
	}

	return newheap_head;

}

//Fais la fusion de deux tas binomiaux
//Retourne un pointeur sur l'élément avec le plus petit rank

//REGLER PETIT PROBLEME ICI
node* mergeHeap(node * heap1, node * heap2)
{

	//Fusionner les deux listes de façon monotone (sans résoudre les doublons)
	node * newheap = fusionnerTasBinomiaux(heap1, heap2);

	//Cas rare : les deux tas sont NULL, on retourne NULL
	if (newheap == NULL)
		return newheap;

	node * x = NULL; //racine en cours d'examen
	node * apres_x = NULL; //racine apres x
	node * avant_x = NULL; //racine avant x


	x = newheap;
	apres_x = newheap->next;



	while (apres_x != NULL)
	{

		//CAS 1 : Les deux arbres binomiaux qui se suivent ont des rangs différents ou alors on a 3 arbres de même rang côte a côte. On déplace le pointeur pour fusionner les 2 derniers
		if (x->rank != apres_x->rank || apres_x->next != NULL && apres_x->next->rank == x->rank )
		{
			avant_x = x;
			x = apres_x;
		}

		else
		{
			//Les 2 arbres ont le même degré : on les fusionne en utilisant l'arbre a plus petite clé comme racine
			if (x->key <= apres_x->key )
			{
				x->next = apres_x->next;
				mergeTree(apres_x, x);
			}

			//Sinon apres-x a une plus petite clé et x va devenir son enfant
			else 
			{
				if (avant_x == NULL)
					newheap = apres_x;
				else //Cas ou on a 3 arbres de suite. On fait pointer avant x sur apres x car apres x va absorber x
					avant_x->next = apres_x;

				mergeTree(x, apres_x);
				x = apres_x;
			}
		}

		apres_x = x->next;
	}

	//On retourne un pointeur sur l'élément de degré moindre (le début de la liste)
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

//Trouver le minimum parmi les racines O(lg n)
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

//Détruit le minimum dans le tas binomial et retourne le nouveau heap.
//Retourne NULL quand le tas est vide

node * extractMin(node * heap)
{
	//First step : We find the minimum x
	node * x = findMinimum(heap);

	//We find the element before x
	node * before = NULL;
	node * iterator = heap;

	while (iterator != x)
	{
		before = iterator;
		iterator = iterator->next;
	}

	//If the minimum node we are deleting is the smallest binomial tree, we will need to return the next root node 
	if (before == NULL) {
		heap = x->next;

	}
	else {
		//We delete the minimum from this list by changing the pointer of the precedent root node
		before->next = x->next;
	}

	//2nd part : Make another binomial heap from the children of x and merge it with our heap
	node * fils = x->child;

	if (fils == NULL) //pas de fils on return tout de suite
	{
		return heap;
	}

	node * courant;
	node * precedent = 0;
	node * frere;
	int i = 0;
	courant = fils;

	//Inverser la liste chainée des fils pour qu'elle soit en ordre croissant au lieu d'être en ordre croissant
	//On utilise 3 pointeurs, precedent courant et frere et on traverse toute la liste en faisant pointer courant sur precedentà
	//Il faut également annuler les pointeurs vers le parent pour que l'opération decrease-key n'aie jamais de problèmes.
	while ( courant != NULL)
	{
		if (precedent > 0)
		{
			courant->parent = NULL; //Annuler le pointeur parent
			frere = courant->next; //Le prochain élément de la liste
			courant->next = precedent;
			precedent = courant;
			courant = frere;
		}
		//1ere itération
		else
		{
		precedent = courant;
		courant = courant->next;
		precedent->next = NULL; //Car cet élément devient le dernier élément de la liste.
		precedent->parent = NULL;
		}
	}
	
	node * teteListeEnfants = precedent;

	node * resultat =  mergeHeap( heap, teteListeEnfants);
	return resultat;
}

/*Puisque les pointeurs sont a sens unique, on doit absolument avoir un système qui ne change que les valeurs
Le problème survient avec l'algorithme de Prim. 
Lorsqu'on fait les decreasekey, il faut pouvoir targetter un sommet en particulier, 
et ce sommet va changer d'emplacement mémoire avec les decreaseKey. 
Il faut donc avoir la discipline de garder une table de pointeurs à jour. */
void swap_parent_child(node * child, node * parent)
{
	int tmp = child->key;
	child->key = parent->key; //on change les valeurs
	parent->key = tmp;
	//On change la table des pointeurs
	int indexParent = parent->i;
	int indexChild = child->i;

	//Le parent prend le pointeur du child et le child de meme
	vertices[indexParent].inHeap = child;
	vertices[indexChild].inHeap = parent;

	//On doit mettre à jour la structure de node aussi pour qu'elle puisse communiquer correctement
	child->i = indexParent;
	parent->i = indexChild;

}

//On change la clé avec celle du parent
//On change les valeurs, tout simplement
void decreaseKey(node * element, int newValue)
{
	//On calcule la valeur de la nouvelle clé
	element->key = newValue;
	node * i = element;

	if (i->parent == NULL)
		return ;

	while (i->parent != NULL)
	{
		int clParent = i->parent->key;
		//Si la clé du parent est plus grosse, on échange les deux éléments et on continue
		if (clParent > i->key )
		{
			swap_parent_child(i, i->parent);
		}
		else break; //Sinon, si la clé du parent est encore plus petite, on sort de la boucle

		//Si on a fait un swap, on continue
		i = i->parent;
	}
}


void printSmall(node * heap)
{
	printf("\n");
	node * racine = heap;
	//Cette racine est le minimum
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
	//Imprimer le niveau courant
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
	//Lire le fichier texte

	//Lire le fichier texte
	FILE* fichier;

	//user used commandline to pass file name
	if (argc == 2) {
		fichier = fopen(argv[1], "r");
	}

	//no file name, search for graph_poids.txt
	else 
		fichier = fopen("graph_poids.txt", "r");

    static char ligne[50]; //pour lire la ligne du fichier
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

		//On delete le min
		heap = extractMin(heap);



		if (heap == NULL)
			break;

		//On fait des decrease key avec toutes les connexions du dernier sommet extrait
		for (int i = 0; i < min->connexions.size() ; i++)
		{
			edge * tmp = min->connexions[i];

			//printf("Decrease key : %d %d %d\n", tmp->vertex1, tmp->vertex2, tmp->weight);

			//Quel est le sommet d'ou part cette connexion?
			//Quel est le sommet de destination (important)
			int destination;
			if ( min->i == tmp->vertex1)
				destination = tmp->vertex2;
			else destination = tmp->vertex1;

			vertice * vertice_destination = &vertices[destination];

			if (!vertice_destination->gone)
			{
				//Si ya pas de best
				if (vertice_destination->best == NULL) {
					pmap[destination]=tmp->vertex1;
					vertice_destination->best = tmp;
					decreaseKey(  vertice_destination->inHeap, tmp->weight);
				}

				//Si ya deja un best, on fait juste le decreasekey si la nouvelle est meilleure
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

		//On trouve un nouveau minimum
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