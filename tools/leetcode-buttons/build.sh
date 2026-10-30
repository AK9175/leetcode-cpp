#!/usr/bin/env bash
# Package this folder as a .vsix (no vsce needed) and install it into VS Code.
set -euo pipefail
HERE="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
VERSION="$(python3 -c 'import json,sys; print(json.load(open(sys.argv[1]))["version"])' "$HERE/package.json")"
TMP="$(mktemp -d)"
mkdir -p "$TMP/extension"
cp "$HERE/package.json" "$HERE/extension.js" "$TMP/extension/"
cat > "$TMP/[Content_Types].xml" <<'XML'
<?xml version="1.0" encoding="utf-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types"><Default Extension=".json" ContentType="application/json"/><Default Extension=".js" ContentType="application/javascript"/><Default Extension=".vsixmanifest" ContentType="text/xml"/></Types>
XML
cat > "$TMP/extension.vsixmanifest" <<XML
<?xml version="1.0" encoding="utf-8"?>
<PackageManifest Version="2.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2011">
  <Metadata>
    <Identity Language="en-US" Id="leetcode-buttons" Version="$VERSION" Publisher="local"/>
    <DisplayName>LeetCode Buttons</DisplayName>
    <Description xml:space="preserve">Run / debug buttons for the local LeetCode C++ workspace.</Description>
    <Properties><Property Id="Microsoft.VisualStudio.Code.Engine" Value="^1.80.0"/></Properties>
  </Metadata>
  <Installation><InstallationTarget Id="Microsoft.VisualStudio.Code"/></Installation>
  <Dependencies/>
  <Assets><Asset Type="Microsoft.VisualStudio.Code.Manifest" Path="extension/package.json" Addressable="true"/></Assets>
</PackageManifest>
XML
rm -f "$HERE/leetcode-buttons.vsix"
(cd "$TMP" && zip -qr "$HERE/leetcode-buttons.vsix" "[Content_Types].xml" extension.vsixmanifest extension)
rm -rf "$TMP"
code --install-extension "$HERE/leetcode-buttons.vsix" --force 2>/dev/null | tail -1
