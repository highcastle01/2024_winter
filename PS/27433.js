let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split(' ');

let num = Number(input);

let ans = 1;

function fact(num){
    if(num == 0){
        return ans;
    }
    ans = ans * num;
    fact(num-1);
}

fact(num);
console.log(ans);