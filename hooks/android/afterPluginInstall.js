#!/usr/bin/env node

var fs = require('fs');
var path = require('path');

function replaceStringInFile(fileName, searchValue, newValue) {
    var originalFileContent = fs.readFileSync(fileName, 'utf8');
    var modifiedFileContent = originalFileContent.replace(searchValue, newValue);
    fs.writeFileSync(fileName, modifiedFileContent, 'utf8');
}

var configurationFile = path.join("plugins", "android.json");
var configuration = JSON.parse(fs.readFileSync(configurationFile, 'utf8'));

// platforms/android/app/src/main/java <-- 8.0.0
// platforms/android/src <-- Cordova 7.1.0
var filesToModify = [
    "platforms/android/app/src/main/java/com/mobbeel/mobbscan/MobbScanDocumentDetectionInterface.java",
    "platforms/android/app/src/main/java/com/mobbeel/mobbscan/MobbScanVideoInterface.java"
];

filesToModify.forEach(function(fileName) {
    if (fs.existsSync(fileName)) {
        var packageName = configuration.installed_plugins["com.mobbeel.mobbscan"]["PACKAGE_NAME"];
        replaceStringInFile(fileName, "import com.mobbeel.mobbscan.R;", "import " + packageName + ".R;");
     }
});
