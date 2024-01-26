const solution = (arr1, arr2) => {
    let n = arr1.length
    let m = arr2.length
    
    let nsum = arr1.reduce((acc, val) => acc + val, 0);
    let msum = arr2.reduce((acc, val) => acc + val, 0);
    
    if(n < m){
        return -1;
    }else if(n > m){
        return 1;
    }else{
        if(nsum < msum){
            return -1;
        }else if(nsum > msum){
            return 1;
        }else{
            return 0;
        }
    }
}