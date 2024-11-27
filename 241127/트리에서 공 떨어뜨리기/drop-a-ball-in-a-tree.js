const fs = require("fs");

const getIndex = (tree,idx,k)=>{
    const leftVal = tree[idx*2];
    const rightVal = tree[idx*2+1];
    const isHaveTwoChild = leftVal!==-1&&rightVal!==-1;
    const isHaveOneChild = leftVal!==-1||rightVal!==-1;
    if(isHaveTwoChild){
        const isOdd = k%2===1;
        const nextK = k>1?Math.floor(k/2):1;
        return isOdd?getIndex(tree,idx*2,k>1?nextK+1:1):getIndex(tree,2*idx+1,nextK)
    }else if(isHaveOneChild){
        return leftVal!==-1?getIndex(tree,idx*2,k):getIndex(tree,2*idx+1,k);
    }else{
        return idx;
    }
    

}

const main = ()=>{
    const inputLines = fs.readFileSync(0).toString().split("\n");
    const n = Number(inputLines[0]);
    const tree = Array.from({length:n+1}).map(()=>-1);
    inputLines.slice(1,n+1).forEach((line,idx)=>{
        if(line!==''){
            const [l,r] = line.split(" ").map(Number);
            const newIdx = idx+1;
            tree[2*newIdx]=l;
            tree[2*newIdx+1]=r;
        }
    })
    const k = Number(inputLines[inputLines.length-1]);
    const ans = getIndex(tree,1,k);
    console.log(tree[ans]);
}

main();