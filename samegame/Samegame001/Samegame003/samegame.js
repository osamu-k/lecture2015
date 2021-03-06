.import QtQuick 2.0 as Quick

var maxColumn = 0
var maxRow = 0
var blockSize = 0
var gameCanvas = null

var maxIndex = 0
var board = null
var block = null;

function index( column, row )
{
    return column + (row * maxColumn)
}

function startNewGame( canvas, nColumn, nRow, blSize )
{
    if( board != null ){
        for( var i = 0; i < maxIndex; i++ ){
            if( board[i] != null ){
                console.log( "destroying block at index " + i )
                console.log( "object is " + board[i] )
                board[i].destroy()
                board[i] = null
            }
        }
    }

    maxColumn = nColumn
    maxRow = nRow
    blockSize = blSize
    gameCanvas = canvas

    maxIndex = nColumn * nRow

    board = new Array(maxIndex)
    for( var column = 0; column < maxColumn; column++ ){
        for( var row = 0; row < maxRow; row++ ){
            console.log( "creating block at index " + index(column,row) )
            board[index(column,row)] = createBlock( column, row )
        }
    }
}

function createBlock( column, row )
{
    if( block == null ){
        block = Qt.createComponent("Block.qml")
    }
    if( block.status == Quick.Component.Ready ){
        var blockObject = block.createObject( gameCanvas )
        if( blockObject != null ){
            blockObject.type = Math.floor( Math.random() * 3 )
            blockObject.x = blockSize * column
            blockObject.y = blockSize * row
            blockObject.width = blockSize
            blockObject.height = blockSize
            return blockObject
        }
        else{
            console.log( "error creating Block" )
            console.log( block.errorString() )
            return null
        }
    }
    else{
        console.log( "error loading Block component" )
        console.log( block.errorString() )
        return null
    }
}
