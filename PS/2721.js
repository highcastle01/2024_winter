const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdin
});

const t = (x) => {
    let tk = 0;
    for (let i = 1; i <= x; i++) {
        tk += i;
    }

    return tk;
}

const w = (n) => {
    let wn = 0;
    for (let i = 1; i <= n; i++) {
        wn += i * t(i + 1);
    }

    console.log(wn);
}

let T;
let input = [];

rl.on('line', function (line) {
    if (!T) {
        T = parseInt(line);
    } else {
        input.push(parseInt(line));
    }
}).on('close', function () {
    for (let i = 0; i < T; i++) {
        w(input[i]);
    }
});
