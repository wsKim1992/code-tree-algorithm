const fs = require('fs');

let latestNode = -1;
let max = -1;

const dfs = (idx,tree,visited,accum)=>{
    let isLeaf = true;
    const {children} = tree[idx];
    for(let i =0 ;i<children.length; i++){
        const nextIdx = children[i]
        if(visited[nextIdx]===true)continue;
        visited[nextIdx]=true;
        isLeaf=false;
        dfs(nextIdx,tree,visited,accum+1);
    }
    if(isLeaf&&max<accum){
        max=accum;
        latestNode=idx;
    }
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    let visited = Array.from({length:n+1}).map(()=>false);
    const tree = Array.from({length:n+1}).map(()=>({children:[]}))
    inputLines.slice(1).forEach(line=>{
        if(line!==''){
            const [fr,to] = line.split(" ").map(Number);
            tree[fr].children.push(to);
            tree[to].children.push(fr);
        }
    })
    dfs(1,tree,visited,0);
    max=0;
    visited=Array.from({length:n+1}).map(()=>false);
    dfs(latestNode,tree,visited,0);
    if(max%2===0){
        console.log(max/2);
    }else{
        console.log(Math.floor(max/2)+1);
    }
}

main();