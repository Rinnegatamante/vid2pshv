<b>Introduction:</b><br>
PSHV (PlayStation Homebrew Video) video format is a video format ideated to simplify the demuxing process and execution on a PSVITA device.<br>
Supported audiocodecs = Vorbis.<br>
Supported videocodecs = H.264<br>
You can find a simple converter from various video format to PSHV here.<br>
<br>
<b>File infos:</b>
<table>
<tr>
<td><b>Offset</b></td>
<td><b>Size</b></td>
<td><b>Info</b></td>
</tr>
<tr>
<td>0x00</td>
<td>4</td>
<td>Magic (the word "PSHV" in ASCII)</td>
</tr>
<tr>
<tr>
<td>0x04</td>
<td>4</td>
<td>Video framerate (Float representation)</td>
</tr>
<tr>
<td>0x08</td>
<td>4</td>
<td>Audio size</td>
</tr>
<td>0x0C</td>
<td>X</td>
<td>Audio buffer</td>
</tr>
<tr>
<td>X</td>
<td>X</td>
<td>Video buffer</td>
</tr>
</table>