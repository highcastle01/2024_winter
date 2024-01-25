const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

const jeonhwa = (n, l, d) => {
    const term = l + 5;

    let song = 0;
    let bell = d;

    for(let i = 0; i < n; i++){
        song += term;
        while(1){
            if(bell < song - 5){
                bell += d;
            }else{
                break;
            }
        }
        if(song - 5 <= bell && bell < song){
            break;
        }
    }

    console.log(bell);
}

let input = [];

rl.on('line', function (line){
    input = line.split(' ').map(Number);
}).on('close', function (){
    jeonhwa(input[0], input[1], input[2]);
})