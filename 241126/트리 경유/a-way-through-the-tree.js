const fs = require('fs');

const search = (tree,idx)=>{
    let dest = idx;
    while(dest>0){
        if(tree[dest]===1){
            break;
        }
        dest/=2;
    }
    return dest;
}

const main = ()=>{
    const inputlines = fs.readFileSync(0).toString().split("\n");
    const [n,q] = inputlines[0].split(" ").map(Number);
    const tree = Array.from({length:n+1});
    const arr = []
    inputlines.slice(1).forEach(line=>{
        if(line!==''){
            arr[arr.length]=Number(line);
        }
    })
    arr.forEach(e=>{
        const result = search(tree,e);
        console.log(result);
        if(!result){
            tree[e]=1;
        }
    })
}

main();