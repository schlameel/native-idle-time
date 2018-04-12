////////////////////////////////////////////////////////
// index.js
//   @fileOverview Exports the proper binary.
//   @author Schlameel
//   @copyright Schlameel
//   @version 1.0.0
//   @license MIT
////////////////////////////////////////////////////////

const binary = require('node-pre-gyp');
const path = require('path')
const binding_path = binary.find(path.resolve(path.join(__dirname, 'package.json')))
var binding = require(binding_path)

module.exports = binding
