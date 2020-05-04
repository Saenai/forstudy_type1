$(document).ready(function () {
    alert("警告文字，ready()指加載完畢");
    $("p").click(function () {
        $(this).hide();
    })
});