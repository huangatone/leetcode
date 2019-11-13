
void display(int a[],int len)
{
	int i=0;
	for(i=0;i<len;i++)
	printf("%d ",a[i]);
	printf("\n");
} 
//QUCKSORT.
void sort(int a[],int left,int right)
{
 
	int i=left,j=right;
	int temp=a[i];
	if(left>=right)//如果左右下标不对，直接返回 。 
	return;
	while(i!=j)
	{
		/*先从右往左，当遇到第一个小于temp的值得时候
		跳出循环。a[i]赋值为a[j],这里的a[i]=temp=a[left];*/ 
		while(i<j&&a[j]>=temp)
		j--;
		if(i<j)
		a[i]=a[j];
		/*在从左往右，当遇到第一个大于temp的时候，跳出循环
		a[j]赋值为a[i]*/
		while(i<j&&a[i]<=temp)
		i++;
		if(i<j)
		a[j]=a[i];	
	 } 
	 a[i]=temp;//然后把中间的值换为temp.然后放区，再次循环。 
	 sort(a,left,i-1);
	 sort(a,i+1,right);
}