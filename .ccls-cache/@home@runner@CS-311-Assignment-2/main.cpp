//Name: Luis Rodriguez
//Date: 02/26/2023
//Class: CS311



#include <iostream>
using namespace std;

struct Node
{
int dance_time;
Node *next;
};

class Queue{
private:
Node* head = nullptr;



public:  
Queue()
{
  head = nullptr;
}

int dequeue();
void enqueue(int total_Cows);
void display();

};

void display();
void enqueue(int total_Cows);
int dequeue();
int cowStage(Queue& q,int stage[],int stageSize,int total_Cows);
int lowest_Element(int stageSize);

int main() {
  


int stageSize = 0;
int total_Cows = 0;
int dance_Time = 0;
int total_Time = 0;
int arraytotal = 0;
  
Queue q;

cout << "How many cows would you like to see in the show!? " << endl;
cin >> total_Cows;
cout << endl;


q.enqueue(total_Cows);

cout << "How many cows would you like to see dance on stage!? " << endl;
cin >> stageSize;
int Stage[stageSize]; 
  

total_Time = cowStage(q,Stage,stageSize,total_Cows);
  
cout << "Total time the cows danced is: ";
cout << total_Time << endl;



  
  
}

int cowStage(Queue &q,int stage[],int stageSize,int total_Cows){
  int total_time = 0;
  int small_time = 0;
  int lowest_time = -1;
  int array_total = 0;
  int temp = 0;
  int templow;
  bool flag = false;
  


  
  
  for (int i = 0; i < stageSize; i++) // loading array from queue
    {
      stage[i] = q.dequeue();
      
    }


  
      while(flag != true)
      {
      array_total = 0;
      lowest_time = -1;
    for (int j = 0; j < stageSize; j++) //for loop to search for lowest element.
      {
        if(lowest_time != 0 && (lowest_time == -1 || lowest_time > stage[j]))
        {
          if(stage[j] == 0)
          {
            continue;
          }
          else
          {
          lowest_time = stage[j];
          
          }
        }
        
      }
        
      
     
      for (int y = 0; y < stageSize; y++) // subtracting lowest from element.
        {
          if(stage[y] != 0 && lowest_time != 0)
          {
          stage[y] -= lowest_time;
          }
          
        }
    
        
        total_time += lowest_time;
        
        for (int z = 0; z < stageSize; z++) //loop to add element if it equals 0
          {
            if (stage[z] <= 0 )
            {
              temp = q.dequeue();
              
              if(temp != 0)
              {
              stage[z] = temp;
              }
            }
          }
         
          for(int f = 0; f < stageSize; f++)
            {
               array_total += stage[f];
              
            }
        
        
          if(array_total == 0)
          {
            flag = true;
          }
  }
  
  return total_time;
}
int Queue::dequeue(){
  int tempValue;
  
  Node* temp = head;
   
  if(head == nullptr)
  {
    return 0;
  }
  
  this->head = this->head->next;
  
  tempValue = temp->dance_time;
  
  delete temp;
  temp = nullptr;
  
  return tempValue;
 }
void Queue::enqueue(int total_Cows){
  Node* temp = this->head;
  int dance_time_temp = 0;
  
  cout << "Input dance times for the cows! " << endl;

  
  for (int i = 0; i < total_Cows; i++)
    {
      
      cin >> dance_time_temp;
      
      if (head == nullptr)
      {
        head = new Node{dance_time_temp,nullptr};
        temp = head;
      }
      else
      {
      temp->next = new Node{dance_time_temp,nullptr};
      temp = temp->next;
      }


      
    }
  cout << endl;
}

void Queue::display()
{
   Node* temp = head;
  if(this->head == nullptr)
  {
    cout << "List is empty" << endl;
    return;
  }
  cout << "Now displaying Queue " << endl;
  while(temp != nullptr) 
  {
    cout << temp->dance_time << " ";
    temp = temp->next;
  }
  cout << endl;
}