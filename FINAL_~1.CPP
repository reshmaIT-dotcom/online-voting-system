#include<iostream.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 10


class VotingSystem
{
private:

    // =====================
    // ARRAY - CANDIDATES //
    // =====================

    struct Candidate
    {
	int id;
	char name[30];
	int votes;
    };

    Candidate candidates[MAX_CANDIDATES];
    int candidateCount;


    // =================
    // QUEUE - VOTERS //
    // =================

    int voterQueue[MAX_VOTERS];

    int front;
    int rear;


    // ==================================
    // STACK - VOTES                  //
    // Stores Voter ID + Candidate ID //
    // ==================================

    struct Vote
    {
	int voterID;
	int candidateID;
    };

    Vote voteStack[MAX_VOTERS];

    int top;


public:
    VotingSystem()
    {
	candidateCount = 0;

	front = -1;
	rear = -1;

	top = -1;
    }

    //Add Candidates:-
    void addCandidates()
    {
	int n;

	cout << "\nEnter number of candidates to add: ";
	cin >> n;

	if(n <= 0)
	{
	    cout << "\nInvalid number!";
	    return;
	}

	if(candidateCount + n > MAX_CANDIDATES)
	{
	    cout << "\nArray Overflow!";
	    cout << "\nMaximum candidates are: "
		 << MAX_CANDIDATES;
	    return;
	}

	for(int i = 0; i < n; i++)
	{
	    candidates[candidateCount].id =
		candidateCount + 1;

	    candidates[candidateCount].votes = 0;

	    cout << "\nEnter name of Candidate "
		 << candidates[candidateCount].id
		 << ": ";

	    cin >> candidates[candidateCount].name;

	    candidateCount++;
	}

	cout << "\nCandidates added successfully!";
    }

    //Delete candidates:-
    void remove_candidates()
    {
	if(candidateCount == 0)
	{
	    cout << "\nArray Underflow!";
	    cout << "\nNo candidates available!";
	    return;
	}

	int rem_id;
	int pos = -1;

	cout << "\nEnter Candidate ID to delete: ";
	cin >> rem_id;


	// SEARCH ID
	for(int i = 0; i < candidateCount; i++)
	{
	    if(candidates[i].id ==rem_id)
	    {
	    pos = i;
		break;
	    }
	}
	if(pos == -1)
	{
	    cout << "\nCandidate not found!";
	    return;
	}

	for(int j = pos; j < candidateCount - 1; j++)
	{
	    candidates[j] = candidates[j + 1];
	}

	candidateCount--;

	cout << "\nCandidate deleted successfully!";
    }


    //Linear search:-
    void search_candidate()
    {
	if(candidateCount == 0)
	{
	    cout << "\nNo candidates available!";
	    return;
	}

	int searchID;
	int found = 0;

	cout << "\nEnter Candidate ID to search: ";
	cin >> searchID;


	for(int i = 0; i < candidateCount; i++)
	{
	    if(candidates[i].id == searchID)
	    {
		cout << "\nCandidate Found!";
		cout << "\nPosition: " << i;
		cout << "\nID: "
		     << candidates[i].id;
		cout << "\nName: "
		     << candidates[i].name;
		cout << "\nVotes: "
		     << candidates[i].votes;

		found = 1;
		break;
	    }
	}


	if(found == 0)
	{
	    cout << "\nCandidate not found!";
	}
    }


    // ARRAY SORTING
    void sortCandidates()
    {
	if(candidateCount == 0)
	{
	    cout << "\nNo candidates available!";
	    return;
	}

	Candidate temp;

	for(int i = 0; i < candidateCount - 1; i++)
	{
	    for(int j = i + 1;
		j < candidateCount;
		j++)
	    {
		if(candidates[i].votes <
		   candidates[j].votes)
		{
		    temp = candidates[i];
		    candidates[i] = candidates[j];
		    candidates[j] = temp;
		}
	    }
	}

	cout << "\nCandidates sorted according to votes!";
    }


    // ARRAY MERGING
    void mergeCandidates()
    {
	if(candidateCount == 0)
	{
	    cout << "\nFirst add some ca	ndidates!";
	    return;
	}


	int secondCount;

	cout << "\nEnter number of candidates "
	     << "in second array: ";

	cin >> secondCount;


	if(secondCount <= 0)
	{
	    cout << "\nInvalid number!";
	    return;
	}


	if(candidateCount + secondCount >
	   MAX_CANDIDATES)
	{
	    cout << "\nArray Overflow!";
	    cout << "\nCannot merge arrays.";
	    return;
	}


	// Temporary second array
	Candidate secondArray[MAX_CANDIDATES];


	// Input second array
	for(int i = 0; i < secondCount; i++)
	{
	    secondArray[i].id =
		candidateCount + i + 1;

	    secondArray[i].votes = 0;

	    cout << "\nEnter name of Candidate "
		 << secondArray[i].id
		 << ": ";

	    cin >> secondArray[i].name;
	}


	// MERGE SECOND ARRAY INTO FIRST ARRAY
	for(int M = 0; M < secondCount; M++)
	{
	    candidates[candidateCount] =
		secondArray[M];

	    candidateCount++;
	}


	cout << "\nTwo arrays merged successfully!";
    }

    //-----------------------
    // DISPLAY CANDIDATES:-
    //-----------------------
    void displayCandidates()
    {
	if(candidateCount == 0)
	{
	    cout << "\nNo candidates available!";
	    return;
	}

	cout << "\n====================================";
	cout << "\n          CANDIDATES";
	cout << "\n====================================\n";


	for(int i = 0; i < candidateCount; i++)
	{
	    cout << "\nID: "
		 << candidates[i].id;

	    cout << "   Name: "
		 << candidates[i].name;

	    cout << "   Votes: "
		 << candidates[i].votes;
	}
    }

    // QUEUE ENQUEUE
    // ADD VOTER :-
    void addVoter()
    {
	// QUEUE OVERFLOW
	if(rear == MAX_VOTERS - 1)
	{
	    cout << "\nQueue Overflow!";
	    cout << "\nVoter Queue is Full!";
	    return;
	}


	int voterID;

	cout << "\nEnter Voter ID: ";
	cin >> voterID;


	// FIRST ELEMENT
	if(front == -1)
	{
	    front = 0;
	}


	rear++;

	voterQueue[rear] = voterID;

	cout << "\nVoter added to Queue!";
    }


    // QUEUE DEQUEUE
    // REMOVE VOTER :-
    int removeVoter()
    {
	// QUEUE UNDERFLOW
	if(front == -1)
	{
	    cout << "\nQueue Underflow!";
	    cout << "\nNo voters in Queue!";
	    return -1;
	}


	int voterID;

	voterID = voterQueue[front];


	// ONLY ONE ELEMENT
	if(front == rear)
	{
	    front = -1;
	    rear = -1;
	}
	else
	{
	    front++;
	}


	return voterID;
    }


    // DISPLAY QUEUE :-
    void displayQueue()
    {
	if(front == -1)
	{
	    cout << "\nQueue Underflow!";
	    cout << "\nVoter Queue is Empty!";
	    return;
	}


	cout << "\n====================================";
	cout << "\n           VOTER QUEUE";
	cout << "\n====================================\n";


	for(int i = front; i <= rear; i++)
	{
	    cout << "\nVoter ID: "
		 << voterQueue[i];
	}
    }


    // CAST VOTE
    // QUEUE DEQUEUE + STACK PUSH :-
    void castVote()
    {
	if(candidateCount == 0)
	{
	    cout << "\nPlease add candidates first!";
	    return;
	}


	// QUEUE UNDERFLOW
	if(front == -1)
	{
	    cout << "\nQueue Underflow!";
	    cout << "\nNo voters available!";
	    return;
	}


	// STACK OVERFLOW CHECK
	if(top == MAX_VOTERS - 1)
	{
	    cout << "\nStack Overflow!";
	    cout << "\nCannot store more votes!";
	    return;
	}


	// GET FIRST VOTER
	int voterID = voterQueue[front];


	cout << "\nVoter ID: "
	     << voterID;


	displayCandidates();


	int choice;

	cout << "\n\nEnter Candidate ID: ";
	cin >> choice;


	// SEARCH CANDIDATE ID
	int pos = -1;

	for(int i = 0; i < candidateCount; i++)
	{
	    if(candidates[i].id == choice)
	    {
		pos = i;
		break;
	    }
	}


	if(pos == -1)
	{
	    cout << "\nInvalid Candidate ID!";
	    return;
	}


	// INCREASE VOTE
	candidates[pos].votes++;


	// =============
	// STACK PUSH
	// =============
	top++;

	voteStack[top].voterID = voterID;
	voteStack[top].candidateID = choice;


	// =================
	// QUEUE DEQUEUE
	// =================
	if(front == rear)
	{
	    front = -1;
	    rear = -1;
	}
	else
	{
	    front++;
	}


	cout << "\nVote cast successfully!";
    }


    // =================
    // STACK POP
    // UNDO LAST VOTE
    // =================

    void undoLastVote()
    {
	// STACK UNDERFLOW
	if(top == -1)
	{
	    cout << "\nStack Underflow!";
	    cout << "\nNo vote available to undo!";
	    return;
	}


	int voterID;
	int candidateID;
	int pos = -1;


	// GET LAST VOTE
	voterID = voteStack[top].voterID;

	candidateID = voteStack[top].candidateID;


	// POP
	top--;


	// FIND CANDIDATE
	for(int i = 0; i < candidateCount; i++)
	{
	    if(candidates[i].id == candidateID)
	    {
		pos = i;
		break;
	    }
	}


	// DECREASE VOTE
	if(pos != -1)
	{
	    candidates[pos].votes--;
	}


	cout << "\nLast vote has been removed!";

	cout << "\nVoter ID: "
	     << voterID;

	cout << "\nCandidate ID: "
	     << candidateID;
    }


    // ================
    // DISPLAY STACK //
    // ================
    void displayStack()
    {
	// STACK UNDERFLOW
	if(top == -1)
	{
	    cout << "\nStack Underflow!";
	    cout << "\nVote Stack is Empty!";
	    return;
	}


	cout << "\n====================================";
	cout << "\n            VOTE STACK";
	cout << "\n====================================\n";


	for(int i = top; i >= 0; i--)
	{
	    cout << "\nVoter ID: "
		 << voteStack[i].voterID;

	    cout << "\nCandidate ID: "
		 << voteStack[i].candidateID;


	    // FIND CANDIDATE NAME
	    int pos = -1;

	    for(int j = 0; j < candidateCount; j++)
	    {
		if(candidates[j].id ==
		   voteStack[i].candidateID)
		{
		    pos = j;
		    break;
		}
	    }


	    if(pos != -1)
	    {
		cout << "\nCandidate Name: "
		     << candidates[pos].name;
	    }


	    cout << "\n----------------------------";
	}
    }


    // ===================
    // DISPLAY RESULTS //
    // ===================

    void displayResults()
    {
	if(candidateCount == 0)
	{
	    cout << "\nNo candidates available!";
	    return;
	}


	cout << "\n====================================";
	cout << "\n          VOTING RESULTS";
	cout << "\n====================================\n";


	for(int i = 0; i < candidateCount; i++)
	{
	    cout << "\n"
		 << candidates[i].name
		 << " : "
		 << candidates[i].votes
		 << " votes";
	}
    }


    // ==================
    // HIGHEST VOTES //
    // ==================
    void findWinner()
    {
	if(candidateCount == 0)
	{
	    cout << "\nNo candidates available!";
	    return;
	}


	int maxVotes = candidates[0].votes;


	for(int i = 1; i < candidateCount; i++)
	{
	    if(candidates[i].votes > maxVotes)
	    {
		maxVotes = candidates[i].votes;
	    }
	}


	if(maxVotes == 0)
	{
	    cout << "\nNo votes have been cast yet!";
	    return;
	}


	cout << "\n====================================";
	cout << "\n        HIGHEST VOTES";
	cout << "\n====================================\n";


	for(int H = 0; H < candidateCount; H++)
	{
	    if(candidates[H].votes == maxVotes)
	    {
		cout << "\n"
		     << candidates[H].name
		     << " - "
		     << candidates[H].votes
		     << " votes";
	    }
	}
    }


    // =============
    // MAIN MENU //
    // =============

    void menu()
    {
	int choice;


	do
	{
	    system("cls");


	    cout << "====================================\n";
	    cout << "        ONLINE VOTING SYSTEM\n";
	    cout << "====================================\n";


	    cout << "\n1. Add Candidates";
	    cout << "\n2. Delete Candidate";
	    cout << "\n3. Search Candidate";
	    cout << "\n4. Merge Candidate Arrays";
	    cout << "\n5. Display Candidates";


	    cout << "\n6. Add Voter";
	    cout<<" \n7. Remove Voter";
	    cout << "\n8. Display Voter Queue";


	    cout << "\n9. Cast Vote";
	    cout << "\n10. Sort Candidates";
	    cout << "\n11. Undo Last Vote";
	    cout << "\n12. Display Vote Stack";



	    cout << "\n13. Display Results";
	    cout << "\n14. Find Highest Votes";


	    cout << "\n\n0. Exit";


	    cout << "\n\nEnter your choice: ";
	    cin >> choice;


	    system("cls");


	    switch(choice)
	    {
		case 1:
		    addCandidates();
		    break;


		case 2:
		    remove_candidates();
		    break;


		case 3:
		    search_candidate();
		    break;

		case 4:
		    mergeCandidates();
		    break;


		case 5:
		    displayCandidates();
		    break;


		case 6:
		    addVoter();
		    break;

		case 7:
		     removeVoter();
		     break;


		case 8:
		    displayQueue();
		    break;


		case 9:
		    castVote();
		    break;


		case 10:
		    sortCandidates();
		    break;



		case 11:
		    undoLastVote();
		    break;


		case 12:
		    displayStack();
		    break;


		case 13:
		    displayResults();
		    break;


		case 14:
		    findWinner();
		    break;


		case 0:
		    cout << "\nThank you for using Voting System!";
		    break;


		default:
		    cout << "\nInvalid choice!";
	    }


	    if(choice != 0)
	    {
		cout << "\n\nPress any key to continue...";
		getch();
	    }


	}while(choice != 0);
    }
};


// ================
// MAIN FUNCTION //
// ================

int main()
{
    VotingSystem system;

    system.menu();

    return 0;
}
