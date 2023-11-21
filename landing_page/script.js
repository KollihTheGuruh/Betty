$(document).ready(function() {
    let currentIndex = 0;

    function showSlide(index) {
        $('.slide').removeClass('active');
        $('.slide').eq(index).addClass('active');
    }

    $('.next').click(function() {
        currentIndex = (currentIndex + 1) % $('.slide').length;
        showSlide(currentIndex);
    });

    $('.prev').click(function() {
        currentIndex = (currentIndex - 1 + $('.slide').length) % $('.slide').length;
        showSlide(currentIndex);
    });
});