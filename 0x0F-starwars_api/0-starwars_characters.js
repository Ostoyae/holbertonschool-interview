#!/usr/bin/node

const request = require('request');

if (process.argv.length < 3) {
  console.error('Missing argument');
  process.exit(1);
}

const args = process.argv.slice(2);

try {
  const jsonChunk = [];
  const api = `https://swapi-api.hbtn.io/api/films/${args[0]}/`;
  request
    .get(api)
    .on('error', function (err) {
      closeWithError(err);
    })
    .on('data', function (data) {
      jsonChunk.push(data);
    }).on('end', () => {
      const chunks = Buffer.concat(jsonChunk);
      const jsonObj = JSON.parse(chunks);

      if ('detail' in jsonObj || !('characters' in jsonObj)) { closeWithError('Not Found'); }
      characterRoster(jsonObj.characters);
    });
} catch (err) {
  console.error('errpr:'.err);
  console.error('error: Invalid Argument - given argment must be a number');
  process.exit(1);
}

function closeWithError (err) {
  console.error(err);
  process.exit(1);
}

function characterRoster (charList) {
  var promisArray = new Array(charList.length);

  for (var i = 0; i < charList.length; i++) {
    promisArray[i] = (new Promise((resolve, reject) => {
      request.get(charList[i])
        .on('data', function (data) { resolve(JSON.parse(data).name); });
    }));
  }

  Promise.all(promisArray).then((val) => {
    val.forEach(element => {
      console.log(element);
    });
  });
}
