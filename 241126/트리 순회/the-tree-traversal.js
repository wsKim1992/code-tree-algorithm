const fs = require("fs")
const process = require('process')
const firstDFS = (leftTree,rightTree,strIdx)=>{
    process.stdout.write(strIdx);
    leftTree[strIdx]!=='.'&&firstDFS(leftTree,rightTree,leftTree[strIdx]);
    rightTree[strIdx]!=='.'&&firstDFS(leftTree,rightTree,rightTree[strIdx]);
}
const secondDFS = (leftTree,rightTree,strIdx)=>{
    leftTree[strIdx]!=='.'&&secondDFS(leftTree,rightTree,leftTree[strIdx]);
    process.stdout.write(strIdx);
    rightTree[strIdx]!=='.'&&secondDFS(leftTree,rightTree,rightTree[strIdx]);
}

const thirdDFS = (leftTree,rightTree,strIdx)=>{
    leftTree[strIdx]!=='.'&&thirdDFS(leftTree,rightTree,leftTree[strIdx]);
    rightTree[strIdx]!=='.'&&thirdDFS(leftTree,rightTree,rightTree[strIdx]);
    process.stdout.write(strIdx);
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const leftTree ={};
    const rightTree = {};
    inputLines.slice(1).forEach(line=>{
        if(line!==''){
            const [p,l,r] = line.split(" ")
            leftTree[p]=l;
            rightTree[p]=r;
        }
    })
    firstDFS(leftTree,rightTree,'A');
    console.log();
    secondDFS(leftTree,rightTree,'A');
    console.log();
    thirdDFS(leftTree,rightTree,'A');
}

main();