/******************************************************************
 * Project Name:  Graph                                           *
 * Programmer  :  Ethan Ray F. Mosqueda                           *
 * Date Completed: October 1, 2016                                *
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************
 * Data Structure Definition of a Graph Implementation  *
 ********************************************************/
 
#define SIZE 5                               /* Maximum size of the array, thus vertices are: 0, 1, 2, 3, 4 */
#define SENTINEL 999      					 /* instead of infinity */
#define APSPMatrix LabeledAdjMatrix

typedef int vertex;

/* arc or directed edge representation */
typedef struct {
	vertex tail;      /* tail vertex of the arc */
	vertex head;      /* head vertex of the arc */
	int weight;       /* weight of the arc      */ 
}arcType;

/* Adjacency List Representation */
typedef struct node {
	vertex adjVertex;    /* adjacent vertex */
	int weight;         /* weight of the associated arc */
	struct node *next;
}*List;
typedef List AdjList[SIZE];                   

/* Labeled Adjacency matrix Representation*/   
typedef int LabeledAdjMatrix[SIZE][SIZE];                                               

/* Bit-Vector Implementation of the set of vertices */
typedef vertex SET[SIZE];    					


/**************************************************
 * Function Prototypes                            *
 **************************************************/
void createAdjList(AdjList L);
void displayAdjList(AdjList L); 

void createLabeledAdjMatrix(LabeledAdjMatrix M, AdjList L);
void displayMatrix(LabeledAdjMatrix M, char *titleMsg);

int *dijkstraSource(LabeledAdjMatrix M, vertex source);
void displayShortestPath(int *D, vertex source);


APSPMatrix * findAPSP(LabeledAdjMatrix M);     /* All Pairs Shortest Path -> dijktra called N times */

int * findEccentricity(APSPMatrix A);
void displayEccentricity(int *ecc);
void displayCenterGraph(int *ecc);



/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *   4)  Uncomment or copy the print statement in each PROBLEM#  if the task is     *
 *       completed.                                                                 *
 ***********************************************************************************/
 int main( ) 
 {	
 /*-------------------------------------------------------------------------------
  * Write all variable declaration here.                                         *
  *------------------------------------------------------------------------------*/
    AdjList L;
    
    
    
/*---------------------------------------------------------------------------------
 * 	Problem #1 ::  Create the adjacency list L representing the directed graph    *
 *                 by calling createAdjList() then call displayAdjList() to       *
 *                 display the adjacent vertices.                                 *
 *                                                                                *
 *  printf("\n\n\nProblem #1:: ");                                                *
 *--------------------------------------------------------------------------------*/
 
   	createAdjList(L);
   	displayAdjList();

/*---------------------------------------------------------------------------------
 * 	Problem #2 ::  Create the labeled adjacency matrix M using the adjacency    *
 *                 list L, then call displayMatrix() to display the Labeled       *
 *                 adjacency matrix.                                              *
                                                          *
 *  printf("\n\n\nProblem #2:: ");                                                *
 *--------------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------------
 * 	Problem #3 ::  Determine the cost of the shortest path from Vertex 2 to the   * 
 *                 other vertices by calling dijkstraSource(), passing the        *
 *                 labeled adjacency matrix M and Vertex 2.                       * 
 *                 Call displayShortestPath() to display the result               *
 *                                                                                *                                         
 *  printf("\n\n\nProblem #3:: ");                                                *
 *--------------------------------------------------------------------------------*/




/*---------------------------------------------------------------------------------
 * 	Problem #4 ::   Determine the APSP cost matrix by calling findAPSP(), then    *
 *                  call displayMatrix().                                         *
 *  printf("\n\n\nProblem #4:: ");                                                *
 *--------------------------------------------------------------------------------*/	


/*---------------------------------------------------------------------------------
 * 	Problem #5 ::  Determine the center of the graph by finding the eccentricity  *
 *                 of each vertex by calling findEccentricity, then display the   *
 *                 the eccentricity of each vertex. Call displayCenterGraph to    *
 *                 display the center(s) of the graph.                            *
 *                                                                                *
 *  printf("\n\n\nProblem #5:: ");                                                *
 *--------------------------------------------------------------------------------*/		


	
 getch();
 return 0;
}


/************************************************************
 *  Problem 1 Function Definitions                          *
 ************************************************************/

void createAdjList(AdjList L)
{
	int const COUNT = 9;
	arcType data[] = { {4, 2, 15}, {0, 1, 10}, {1, 2, 50}, {2, 0, 20}, {0, 4, 100},
					   {3, 4, 60}, {0, 3, 20}, {3, 2, 20}, {2, 4, 10}       
                     };


            /***********************************************
                * Write  your code fragment here.                                         *
                ***********************************************/                    

}


void displayAdjList(AdjList L)
{
	vertex v;
	List temp;
	
	printf("\n\nThe Adjacency List ::");
	printf("\n%-8s", "VERTEX");
	printf("%-20s", "Adjacent vertices");
	printf("\n%-8s", "------");
	printf("%-20s", "-----------------");
	 /***********************************************
                * Write  your code fragment here.                                         *
                ***********************************************/                    	
	printf("\n\nPress any key to continue ... ");
	getch();
		
} 

/************************************************************
 *  Problem 2 Function Definitions                          *
 ************************************************************/ 



/************************************************************
 *  Problem 3 Function Definitions                          *
 ************************************************************/

void displayShortestPath(int *D, vertex source)
{
	int x;
	
	printf("\n\nShortest Path from Source Vertex %d", source);
    printf("\n----------------------------------") ;
	printf("\n%15s", "Vertex::");
	for(x = 0; x < SIZE; x++){
		printf("%8d", x);
	}
	
	printf("\n%15s", "Distance::");
	/***********************************************
                * Write  your code fragment here.                                         *
                ***********************************************/                    

	
	printf("\n\nPress any key to continue ... ");
	getch();	
}


/************************************************************
 *  Problem 4 Function Definitions                          *
 ************************************************************/


/************************************************************
 *  Problem 5 Function Definitions                          *
 ************************************************************/


