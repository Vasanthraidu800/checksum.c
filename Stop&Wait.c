#include<stdio.h>
int main()
{
int size,sent=0,ack,I;
printf("Enter number of freames to be transferred:");
scanf("%d",&size);
while(sent<size)
{
printf("frame %d has been transmitted \n",sent);
while(1)
{
printf("Enter your choice:\n 1.For ACK \n 2.For NACK\n");
printf("Choice:");
scanf("%d",&ack);
if(ack==1)
{
printf("The frame %d has been acknowledged \n",sent);
break;
}
else if(ack ==2)
{
printf("The frame %d has not been acknowledged re-trasmitting……..\n",sent);
 continue;
}
else
{
printf("Invalid choice . please enter your choice:\n 1.For ACK \n 2.For NACK\n");
}
}
sent++;
}
printf("All frames have been transmitted and acknowledged.\n");
return 0;
}
