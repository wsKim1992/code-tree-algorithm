const fs = require("fs");
const MAX_N=200000;
let ans = -1;
const getIndex = (leftTree,rightTree,idx,k)=>{
    const leftVal = leftTree[idx];
    const rightVal = rightTree[idx];
    if(leftVal==-1&&rightVal==-1){
        ans=idx;
        return;
    }
    if(leftVal==-1){
        getIndex(leftTree,rightTree,rightVal,k);
    }else if(rightVal==-1){
        getIndex(leftTree,rightTree,leftVal,k);
    }else if(k%2n==1){
        getIndex(leftTree,rightTree,leftVal,(k+BigInt(1))/BigInt(2));
    }else{
        getIndex(leftTree,rightTree,rightVal,k/BigInt(2));
    }
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const tree = Array.from({length:n+1}).map(()=>-1);
    const leftTree = Array.from({length:MAX_N+1}).map(()=>-1);
    const rightTree = Array.from({length:MAX_N+1}).map(()=>-1)
    inputLines.slice(1,n+1).forEach((line,idx)=>{
        if(line!==''){
            const [l,r] = line.split(" ").map(Number);
            const newIdx = idx+1;
            leftTree[newIdx]=l;
            rightTree[newIdx]=r;
        }
    })
    const k = BigInt(inputLines[n+1]);
    getIndex(leftTree,rightTree,1,k);
    console.log(ans);
}

main();