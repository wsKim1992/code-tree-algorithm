const fs = require('fs');

const search = (tree,idx,start)=>{
    if(idx===1){
        tree[start]=1;
        return {isPossible:true,idx}
    }
        if(tree[idx]===1)return {isPossible:false,idx}

    return search(tree,Math.floor(idx/2),start)
}

const main = ()=>{
    const inputlines = fs.readFileSync(0).toString().split("\n");
    const [n,q] = inputlines[0].split(" ").map(Number);
    const tree = Array.from({length:n+1}).map(()=>0);
    const arr = []
    inputlines.slice(1).forEach(line=>{
        if(line!==''){
            arr[arr.length]=Number(line);
        }
    })
    arr.forEach(e=>{
        const {isPossible,idx} = search(tree,e,e);
        console.log(isPossible?Number(!isPossible):idx);
    })
}

main();