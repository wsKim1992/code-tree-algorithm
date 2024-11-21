const fs = require("fs");

let minDist = 100000;
let maxDepth = -1;
let latestIdx= -1;

const dfs = (idx,tree,visited,accumDepth,accumDist)=>{
    let isLeaf = true;
    const {children} = tree[idx]
    for(let i =0 ;i<children.length;i++){
        const {idx:nextIdx,w} = children[i];
        if(visited[nextIdx]===true) continue;
        isLeaf=false;
        visited[nextIdx]=true;
        dfs(nextIdx,tree,visited,accumDepth+1,accumDist+w);
    }
    if(isLeaf===true){
        if(maxDepth<accumDepth){
            maxDepth=accumDepth;
            minDist=accumDist;
            latestIdx=idx;
        }else if(maxDepth===accumDepth&&minDist>accumDist){
            maxDepth=accumDepth;
            minDist=accumDist;
            latestIdx=idx;
        }
    }
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const [n,d] = inputLines[0].split(" ").map(Number);
    const tree = Array.from({length:n+1}).map(()=>({children:[]}));
    let visited = Array.from({length:n+1}).map(()=>false);
    inputLines.slice(1).forEach(line=>{
        if(line!==''){
            const [x,y,w] = line.split(" ").map(Number);
            tree[x].children.push({idx:y,w});
            tree[y].children.push({idx:x,w});
        }
    })
    visited[1]=true;
    dfs(1,tree,visited,0,0);
    minDist=100000;
    maxDepth=0;
    visited=Array.from({length:n+1}).map(()=>false);
    visited[latestIdx]=true;
    dfs(latestIdx,tree,visited,0,0);
    if(minDist%d===0){
        console.log(minDist/d)
    }else{
        console.log(Math.floor(minDist/d)+1);
    }
}

main();