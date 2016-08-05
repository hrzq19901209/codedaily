quickSort(int s, int e, int array[]){
    if(s < e){
        int x=array[s], i=s, j=e;
        while(i < j){
            while(i < j && array[j] >= x){
                j--;    
            }
            if(i < j)
              array[i++] = array[j];
            while(i < j && array[i] < x){
                i++
            }
            if(i < j)
               array[j--] = array[i];
    }        
    array[i] = x;
    quickSort(s,i-1,array);
    quickSort(i+1,e,array);
}
