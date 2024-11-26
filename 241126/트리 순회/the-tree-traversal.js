const fs = require("fs")
const process = require('process')
const firstDFS = (tree,idx)=>{
    if(tree[idx]==='.')return;
    process.stdout.write(tree[idx]);
    firstDFS(tree,idx*2)
    firstDFS(tree,idx*2+1)
}
const secondDFS = (tree,idx)=>{
    if(tree[idx]==='.')return ;
    secondDFS(tree,idx*2);
    process.stdout.write(tree[idx]);
    secondDFS(tree,idx*2+1);
}

const thirdDFS = (tree,idx)=>{
    if(tree[idx]==='.')return;
    thirdDFS(tree,idx*2);
    thirdDFS(tree,idx*2+1);
    process.stdout.write(tree[idx]);
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const tree = Array.from({length:Math.pow(2,n+1)}).map(()=>'.');
    const location = {};
    inputLines.slice(1).forEach((line,idx)=>{
        if(line!==''){
            const [p,l,r] = line.split(" ")
            if(location[p]===undefined){
                location[p]=idx+1;
            }
            tree[location[p]]=p;
            if(l!=='.'){
                if(location[l]===undefined){
                    location[l]=location[p]*2
                }
                tree[location[l]]=l;
            }
            if(r!=='.'){
                if(location[r]===undefined){
                    location[r]=location[p]*2+1;
                }
                tree[location[r]]=r;
            }
        }
    })
    firstDFS(tree,1);
    console.log()
    secondDFS(tree,1);
    console.log()
    thirdDFS(tree,1);
}

main();