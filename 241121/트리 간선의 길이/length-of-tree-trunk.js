const fs = require('fs');

let max = 0;
let latestNode = -1
const dfs = (idx,dist,visited,accum)=>{
    let isLeaf = true;
    const {children} = dist[idx]
    for(let i =0;i<children.length;i++){
        const {idx:nextIdx,w} = children[i]
        if(visited[nextIdx]===true)continue;
        visited[nextIdx]=true;
        isLeaf=false;
        dfs(nextIdx,dist,visited,accum+w)
    }
    if(isLeaf===true&&max<accum){
        max=accum;
        latestNode=idx;
    }
}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const dist = Array.from({length:n+1}).map(()=>({children:[]}));
    let visited = Array.from({length:n+1}).map(()=>false);

    inputLines.slice(1).forEach(line=>{
        if(line!==''){
            const [x,y,w] = line.split(" ").map(Number)
            dist[x].children.push({idx:y,w:w});
            dist[y].children.push({idx:x,w:w});
        }
    })
    dfs(1,dist,visited,0);
    max=0;
    visited=Array.from({length:n+1}).map(()=>false);
    
    latestNode!==-1&&dfs(latestNode,dist,visited,0)
    console.log(max);
}

main();
