#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Garage{
    char name[30];
    char name_of_garage[30];
    char car_Year[30];
    char car_model[30];
    char car_owner[30];
    char auto_problem[30];
    char part_required[30];
    int costOfPart;
    int labor_in_Hour;
    int repair_cost;
    struct Garage *next; //pointer to the next block of memory to find dog structure
};

struct Garage *GenerateLinkedList2();
void FillStructData2(struct Garage *current); 
void browseEntries(struct Garage *current);
struct Garage *addNewItem(struct Garage *start);
struct Garage *addFirstItem();
struct Garage *deleteEntry(struct Garage *start);
struct Garage *modify(struct Garage *start);
struct Garage *deleteEndNode(struct Garage *start);
struct Garage *search(struct Garage *start);
void monthEarns(struct Garage *start);
struct Garage *deleteFirstNode(struct Garage *start);
void WriteListToFile(struct Garage *start);
void CleanUp(struct Garage *start);
struct Garage *ReadListIn(struct Garage *start);
struct Garage *ReadNextFromFile(struct Garage *start, FILE *pFile);
struct Garage *sort(struct Garage *start);

int main(){
    int begin;
    int ch;
    int press;
    //you will need a pointer to start of the list. IT SHALL NEVER MOVE*
    //*Unless you re-oder the elements.
    //However ENTRY (FIRST) NODE MUST ALWAYS BE PRESERVED

    struct Garage *start;
    start = 0;
    //we will define a second pointer so we can garage through the list and find the
    //last entry in the list (for adding new nodes)

    struct Garage *garage;
    puts(" Project C Garage \n");

    puts(" Press 1 to Start OR 2 to load Previous Data");
    scanf("%d", &begin);
    while ((ch = getchar()) != '\n' && ch != EOF);
    if (begin == 1){
        while (begin == 1){
        
            if (begin == 1){
                puts("\nPRESS 1 to Add new entries \n PRESS 2 to Browse entries \n PRESS 3 to Modify entry \n PRESS 4 to Delete Entry \n PRESS 5 to Save Entry \n PRESS 6 to Sort Entry \n PRESS 7 Search Person's Name Title \n PRESS 8 for Monthly Earnings");
                scanf("%d", &press);
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                    
                if (press == 1)
                {
    
                    if (start == 0) { 
                        start = addFirstItem(); 
                    } else { 
                        addNewItem(start); 
                    }

                }else if (press == 2)
                {
                    browseEntries(start);
                }else if (press == 3)
                {                        
                    modify(start);
                }else if (press == 4)
                {
                    start=deleteEntry(start);
                }else if (press == 5)
                {
                    WriteListToFile(start);
                }else if (press == 6)
                {
                    start = sort(start);
                }else if (press == 7)
                {
                    search(start);
                }else if (press == 8)
                {
                    monthEarns(start);
                }else{
                    puts("INVALID INPUT! READ THE INSTRUCTIONS");
                    exit(1);
                }
            }
        }
    }else if (begin == 2){
        puts("Loading Previously Stored Data");
        start = ReadListIn(start);

        while (begin == 2){
        
            if (begin == 2){
                puts("\nPRESS 1 to Add new entries \n PRESS 2 to Browse entries \n PRESS 3 to Modify entry \n PRESS 4 to Delete Entry \n PRESS 5 to Save Entry \n PRESS 6 to Sort Entry \n PRESS 7 Search Car owner name \n PRESS 8 for Monthly Earnings");
                scanf("%d", &press);
                while ((ch = getchar()) != '\n' && ch != EOF) ;
                    
                if (press == 1)
                {
    
                    if (start == 0) { 
                        start = addFirstItem(); 
                    } else { 
                        addNewItem(start); 
                    }

                }else if (press == 2)
                {
                    browseEntries(start);
                }else if (press == 3)
                {                        
                    modify(start);
                }else if (press == 4)
                {
                    start=deleteEntry(start);
                }else if (press == 5)
                {
                    WriteListToFile(start);
                }else if (press == 6)
                {
                     start = sort(start);
                }else if (press == 7)
                {
                    search(start);
                }else if (press == 8)
                {
                    monthEarns(start);
                }else{
                    puts("INVALID INPUT! READ THE INSTRUCTIONS");
                    exit(1);
                }
            }
        }
    }else{
        
        puts("INVALID INPUT! READ THE INSTRUCTIONS");
        exit(2);
    } 
       
    return 0;
}

struct Garage *GenerateLinkedList2(){

    struct Garage *start, *current, *last;

    int count = 0;
    char keep = 'y';
    int ch;

    while (keep == 'y'){
        
        if (count == 0){

            //set up first node. asign start
            current = (struct Garage*)malloc(sizeof(struct Garage));
            if (current == NULL) {
                puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
                exit(1);
            }

            start = current;
            count++;
            FillStructData2(current);
            current->next = 0;
            last = current;
        }else
        {
            //set up next node. link to last node
            current = (struct Garage*)malloc(sizeof(struct Garage));
            if (current == NULL) {
                puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
                exit(1);
            }
            count++;
            FillStructData2(current);
            current->next = 0;
            last->next = current; // link it to a memory before last = current;
            last = current;
        }

        puts("Enter new info? y/n\n");
        scanf("%c", &keep);
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return start;
}
//fill data
void FillStructData2(struct Garage *current){
    int ch;
    puts("Enter Michanic Name: ");
    scanf("%s", current->name);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Garage Name: ");
    scanf("%s", current->name_of_garage);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter year of Car: ");
    scanf("%s", current->car_Year);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Car Model: ");
    scanf("%s", &current->car_model);
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    puts("Enter Car's owner: ");
    scanf("%s", &current->car_owner);
    while ((ch = getchar()) != '\n' && ch != EOF);
   
    puts("Enter Automated Problem: ");
    scanf("%d", &current->auto_problem);
    while ((ch = getchar()) != '\n' && ch != EOF);

    puts("Enter Part required: ");
    scanf("%s", current->part_required);
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    puts("Enter Cost of part ");
    scanf("%d", &current->costOfPart);
    while ((ch = getchar()) != '\n' && ch != EOF);


    puts("Enter labor in hour ");
    scanf("%d", &current->labor_in_Hour);
    while ((ch = getchar()) != '\n' && ch != EOF);

 
    puts("Enter Cost of repair ");
    scanf("%d", &current->repair_cost);
    while ((ch = getchar()) != '\n' && ch != EOF);
}
//Browse Entries
void browseEntries(struct Garage *current){
    struct Garage *garage;
    int count = 0;
    int check;

    //garage through the list and display
    garage = current;
    while (garage->next != 0){
        count++;
        printf("\nEntry NO: %d\n", count);
        printf("Mechanic Name: %s \n",garage->name);
        printf("Name of Garage: %s \n",garage->name_of_garage);
        printf("Car's Year %s \n",garage->car_Year);
        printf("Car Model %s \n",garage->car_model);
        printf("Car's owner: %s \n",garage->car_owner);
        printf("Automated Problem %s \n",garage->auto_problem);
        printf("Part Required: %s \n",garage->part_required);
        printf("Cost of part: %d \n",garage->costOfPart);
        printf("Labor in hour: %d \n",garage->labor_in_Hour);
        printf("Cost of repair: %d \n",garage->repair_cost);
        puts("---------------------------------------");

        if (garage->next != 0)
        {
            int ch;
            puts("Press 1 to keep browsing entries ||Press 2 to stop");
            scanf("%d", &check);
            while ((ch = getchar()) != '\n' && ch != EOF);
            if (check == 1)
            {
                garage = garage->next;
            }else if (check == 2)
            {
            	
                break;
            }
          
        }
        
    }

    if (check != 2) {
        count++;
        printf("\nEntry NO: %d\n", count);
        printf("Mechanic Name: %s \n",garage->name);
        printf("Name of Garage: %s \n",garage->name_of_garage);
        printf("Car's Year %s \n",garage->car_Year);
        printf("Car Model %s \n",garage->car_model);
        printf("Car's owner: %s \n",garage->car_owner);
        printf("Automated Problem %s \n",garage->auto_problem);
        printf("Part Required: %s \n",garage->part_required);
        printf("Cost of part: %d \n",garage->costOfPart);
        printf("Labor in hour: %d \n",garage->labor_in_Hour);
        printf("Cost of repair: %d \n",garage->repair_cost);
        puts("End of list\n");
    }

}

//Adding First Node
struct Garage *addFirstItem(){ 
    struct Garage *start, *current, *last;
    int ch;
    //set up first node. asign start
    current = (struct Garage*)malloc(sizeof(struct Garage));
    if (current == NULL) {
        puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
        exit(1);
    }

    start = current;
    FillStructData2(current);
    current->next = 0;
    last = current;

    return start;
}
//Adding additional Nodes
struct Garage *addNewItem(struct Garage *start){
    struct Garage  *current, *last;
    current = start;
    int ch;

    while (current->next != 0){
        current = current->next; // link it to a memory before last = current;
    } 
    last = current;
    //set up next node. link to last node
    current = (struct Garage*)malloc(sizeof(struct Garage));
    if (current == NULL) {
        puts("MEMORY ALLOCATION ERROR. Node 1. Exiting...");
        exit(1);
    }

    FillStructData2(current);
    current->next = 0;
    last->next = current;

    return current;
}
//Modifying
struct Garage *modify(struct Garage *start){
    struct Garage  *current, *last;
    current = start;
    int ch, count, entry;
    puts("Enter the number of entry you want to modify\n");
    scanf("%d", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    count = 0;
    while (current->next != 0){
       
        
        count++;
        if (entry == count)
        {
            break;
        }
         current = current->next;
    
    }
  
    FillStructData2(current);            
}
//Delete Entry
struct Garage *deleteEntry(struct Garage *start){
    struct Garage  *current, *last ,*previous;
    current = start;
    int ch, count, entry;
    puts("Enter the number of entry you want to DELETE\n");
    scanf("%d", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    count = 0;
    //deleting First Entry
    if (entry == 1){
                    
        start = deleteFirstNode(start);        

    }else{

        while (current->next != 0){
   
            count++;
            
            if (entry == count)
            {
            
                break;
            }
            previous = current;
            current = current->next;
    
        }
        if (current->next != 0){
            previous->next = current->next;
            free(current);
            puts("\nThe selected Entry has been deleted\n");
            current = previous->next;
        }else
        {            
            deleteEndNode(start);                        
        }   
    }   
    return start;          
}

//Deleting first node
struct Garage *deleteFirstNode(struct Garage *start){
    struct Garage  *current, *last, *garage ,*previous;
    current = start;

    if (start != NULL && start != 0) 
    {
        current = start->next;
    }
    free(start);
    start = current;
    return current;

}

//Deleting Last Node
struct Garage *deleteEndNode(struct Garage *start){
    struct Garage  *current, *last ,*previous;
    current = start;

    if(current == 0){
        puts("Deletion not possible");
    }else{
        previous = 0;
        last = current;
        while(last->next != 0){
            previous = last;
            last = last->next;
        }
        if (previous == 0){
            current = 0;
        }else
        {
            previous->next = 0;
            free(last);
        }
        
    }
}
//Search Function with Garage name as search key
struct Garage *search(struct Garage *start){
    struct Garage  *current, *last, *garage ,*previous;
    current = start;
    int ch;
    char entry[30];
    puts("Enter the Person's name to search for\n");
    scanf("%s", &entry);
    while ((ch = getchar()) != '\n' && ch != EOF);
    while (current != 0)
    {
        if(strcmp(current->car_owner, entry) == 0){
            garage=current;
            puts("\nMATCH FOUND\n");
        printf("Mechanic Name: %s \n",garage->name);
        printf("Name of Garage: %s \n",garage->name_of_garage);
        printf("Car's Year %s \n",garage->car_Year);
        printf("Car Model %s \n",garage->car_model);
        printf("Car's owner: %s \n",garage->car_owner);
        printf("Automated Problem %s \n",garage->auto_problem);
        printf("Part Required: %s \n",garage->part_required);
        printf("Cost of part: %d \n",garage->costOfPart);
        printf("Labor in hour: %d \n",garage->labor_in_Hour);
        printf("Cost of repair: %d \n",garage->repair_cost);
            break;
        }
        current = current->next;
    }
    
}
//Calculating Movie Monthly Earns
void monthEarns(struct Garage *start){
    struct Garage  *current, *last, *garage ,*previous;
    current = start;
    double total = 0.00;

    while (current->next != 0){
   
        total += (current->repair_cost);
    
        current = current->next;
    
    }

    total += (current->repair_cost);

    printf("\nRental Monthly Earnings: %.2f\n", total);

}

// Write Data or save data to file
void WriteListToFile(struct Garage *start) {
	FILE *pFile;
	pFile = fopen("project.bin", "wb");
    
	
	if(pFile != 0) {
        struct Garage  *current, *holdNext, *garage ,*holdPrevious;
        current = start;		
		holdNext = 0;
		holdPrevious = 0;
		
		while(current != 0) {
			holdNext = current->next;
						
			current->next = NULL;
						
			fseek(pFile, 0, SEEK_END);
			fwrite(current, sizeof(struct Garage), 1, pFile);
			
			printf("Writing:%s to file\n",current->name);
			
			current->next = holdNext;
			
			
			holdNext = NULL;
			holdPrevious = NULL;
			
			current = current->next;
		}
		fclose(pFile);
		pFile = NULL;
	} else {
		printf("FILE OPEN ERROR\n");
	}
	
}

//Cleanup function
void CleanUp(struct Garage *start) {
    struct Garage  *current, *freeMe, *holdMe;	
	freeMe = start;
	holdMe = NULL;	
	while(freeMe != NULL) {
		holdMe = freeMe->next;
		printf("Free Name:%s is now free\n",
			freeMe->name);
		free(freeMe);
		freeMe = holdMe;
	}	
}

//Read  next From File
struct Garage *ReadNextFromFile(struct Garage *start, FILE *pFile) {
	size_t returnValue;
	if(start == NULL) {
		start = malloc(sizeof(struct Garage));
		returnValue = fread(start, sizeof(struct Garage), 1, pFile);
		start->next = NULL;
	} else {
		struct Garage *indexMovie = start;
		struct Garage *newEntr = malloc(sizeof(struct Garage));
		while(indexMovie->next != NULL) {
			indexMovie = indexMovie->next;
		}
		returnValue = fread(newEntr, sizeof(struct Garage), 1, pFile);
		indexMovie->next = newEntr;
		newEntr->next = NULL;
		
	}
	return start;
}
// Main Reading from file
struct Garage *ReadListIn(struct Garage *start) {
	
	FILE *pFile;
	pFile = fopen("project.bin", "rb");
	if(pFile != NULL) {
	
		CleanUp(start);
		start = NULL;
		
		fseek(pFile, 0, SEEK_END);
		long fileSize = ftell(pFile);
		rewind(pFile);
		
		int numEntries = (int)(fileSize / (sizeof(struct Garage)));
		printf("numEntries:%d\n",numEntries);
		
		int loop = 0;
		for(loop = 0; loop < numEntries; ++loop) {
			fseek(pFile, (sizeof(struct Garage) * loop), SEEK_SET);
			start = ReadNextFromFile(start, pFile);
		}
	}  else {
		printf("FILE OPEN ERROR FOR READ\n");
	}
	
	return start;

}
//Sorting Function
struct Garage *sort(struct Garage *m_array){
    struct Garage *m1, *m2;
    struct Garage *temp;

    int noOfNodes = 1;

    while(m_array != 0) {
        noOfNodes++;
    }
    //noOfNodes++;
    m1 = m_array;
    int i;
    for (i = 0; i < noOfNodes-1; i++)
    {
        m2=m1;
        int j;
        for ( j = i+1; j < noOfNodes; j++)
        {
            m2 = m2->next;
            if (strcmp(m1->name, m2->name) > 0)
            {
            //    temp->next = m1->next;
            //    m1->next = m2->next;
            //    m2->next = temp->next;

                strcpy(temp->name, m1->name);
                strcpy(temp->name_of_garage, m1->name_of_garage);
                strcpy(temp->car_Year, m1->car_Year);  
				strcpy(temp->car_model, m1->car_model);
				strcpy(temp->car_owner, m1->car_owner); 
				strcpy(temp->auto_problem, m1->auto_problem);  
				strcpy(temp->part_required, m1->part_required);          
                temp->costOfPart = m1->costOfPart;
                temp->labor_in_Hour = m1->labor_in_Hour;
                temp->repair_cost = m1->repair_cost;
                //temp->next = i->next;

                strcpy(m1->name, m2->name);
                strcpy(m1->name_of_garage, m2->name_of_garage);
                strcpy(m1->car_Year, m2->car_Year);  
				strcpy(m1->car_model, m2->car_model);
				strcpy(m1->car_owner, m2->car_owner); 
				strcpy(m1->auto_problem, m2->auto_problem);  
				strcpy(m1->part_required, m2->part_required);          
                m1->costOfPart = m2->costOfPart;
                m1->labor_in_Hour = m2->labor_in_Hour;
                m1->repair_cost = m2->repair_cost;
                //i->next = j->next;

                strcpy(m2->name, temp->name);
                strcpy(m2->name_of_garage, temp->name_of_garage);
                strcpy(m2->car_Year, temp->car_Year);  
				strcpy(m2->car_model, temp->car_model);
				strcpy(m2->car_owner, temp->car_owner); 
				strcpy(m2->auto_problem, temp->auto_problem);  
				strcpy(m2->part_required, temp->part_required);          
                m2->costOfPart = temp->costOfPart;
                m2->labor_in_Hour = temp->labor_in_Hour;
                m2->repair_cost = temp->repair_cost;
                //j->next = i->next;
            
            }
            
        }
        m1 = m1->next;
    }
    m_array = m1;
    return m_array;
}        
     
