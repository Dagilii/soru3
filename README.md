# soru3
trie yapısı

Mehmet Akif Akay 1236706060

# Trie Yapısı Nedir?

    Metin ağaçları, her düğümün kendisinden sonra gelen harfi işaret ettiği ağaçlardır. Bsditçe üzerine bir metin
kodlanabilir ve bu metni veren ağacın üzerinde tek bir yol izlenebilir(deterministic).

Bu boş metin hangi harf ile devam edilirse ilgili kolu takip eder ve gitmiş olduğu düğüm o ana kadar geçmiş olduğu kollardaki harflerin birleştirilmiş halidir. Bir düğümden bir harf taşıyan sadece bir kol çıkabilir.

Trie ağacının ismi retrieval kelimesininin ortasındaki 4 harften gelmektedir.

Metin ağaçlarının (trie), ikili arama ağaçlarına göre en önemli avantajları bir metni aramanın, metin boyutu kadar işlem gerektirmesidir. İkili arama ağaçlarında ise bu süre log n kadar varkit almaktadır. Buradaki n, ağaçtaki düğüm sayısıdır dolayısıyla ikili arama ağaçları, ağaçtaki bilgiye göre hızlı veya yavaş çalışırken, metin ağaçları, ağaçta ne kadar bilgi bulunduğundan bağımsız olarak çalışırlar.

Metin ağaçları hafızayı da verimli kullanırlar çünkü bir metin ağacının en derin noktası, ağaç üzerindeki en uzun metin kadardır. İkili ağaçlarda ise bu derinlik eklenen düğüm sayısına göre en kötü ihtimalle düğüm sayısı kadar olabilmektedir.

Ayrıca metin ağaçları en uzun önek eşlemesi (longest prefix matching) gibi problemlerin çözümünde de avantaj sağlar.