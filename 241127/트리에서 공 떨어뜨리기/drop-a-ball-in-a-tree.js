const fs = require("fs");
const MAX_N=200000;
let ans = -1;
const getIndex = (leftTree,rightTree,idx,k)=>{
    const leftVal = leftTree[idx];
    const rightVal = rightTree[idx];
    const isHaveTwoChild = leftVal!==-1&&rightVal!==-1;
    const isHaveOneChild = leftVal!==-1||rightVal!==-1;
    if(isHaveTwoChild){
        const isOdd = k%2===1;
        return isOdd?getIndex(leftTree,rightTree,leftTree[idx],(Math.floor((k+1)/2))):getIndex(leftTree,rightTree,rightTree[idx],Math.floor(k/2))
    }else if(isHaveOneChild){
        return leftVal!==-1?getIndex(leftTree,rightTree,leftTree[idx],k):getIndex(leftTree,rightTree,rightTree[idx],k);
    }else{
        return idx;
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
    const k = Number(inputLines[inputLines.length-1]);
    const ans = getIndex(leftTree,rightTree,1,k);
    console.log(ans);
}

main();