var addon = require('./build/Release/qos');

console.log(addon);
addon.hello();

function async(value) {
  function callback(err, result) {
    if (err) {
      console.log(err);
      return;
    }
    console.log('async : ' + result);
  }

  addon.calculateAsync(value, callback);
}

function sync(value) {
  var result = addon.calculateSync(value);
  console.log('sync : ' + result);
}

async(2);
sync(3);
sync(5);
async(6);
async(8);
sync(9);

