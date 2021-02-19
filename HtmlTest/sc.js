
class CardHtmlData
{
	constructor(card_obj, data)
	{
		
		this.card_obj = card_obj;
		this.card_obj.type = "button";
		this.text = data.name;
		this.card_obj.innerHTML = this.text;
		this.data = data;
	}
}

class CardGameData
{
	constructor(name, power, hp)
	{
		this.name = name;
		this.power = power;
		this.hp = hp;
	}
}



var card = new Array(3);


var cdb = [["A", 1, 1],
		   ["B", 1, 1],
		   ["C", 1, 1],
		   ];


window.onload = function initalize() {
	

	for(var i = 0; i < 3;i++)
	{
		var line_table = document.createElement("div");
		document.body.appendChild(line_table);
		card[i] = new Array(3);
		for(var j = 0; j < 3;j++)
		{
			var d = getCardData(Math.floor(Math.random()*3));
			card[i][j] = new CardHtmlData(document.createElement("card"), d);
			line_table.appendChild(card[i][j].card_obj);
			card[i][j].card_obj.onclick = function() {
				useCard(d);
			};
		}	
	}

}


function useCard(card)
{
	alert(card.name);
}

function getCardData(card_id)
{
	return new CardGameData(cdb[card_id][0], cdb[card_id][1], cdb[card_id][2]);
}

